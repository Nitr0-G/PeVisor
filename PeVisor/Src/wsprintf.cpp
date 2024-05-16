#include "wsprintf.h"
#include "Crt.hpp"

/***********************************************************************
 *           WPRINTF_ParseFormatA
 *
 * Parse a format specification. A format specification has the form:
 *
 * [-][#][0][width][.precision]type
 *
 * Return value is the length of the format specification in characters.
 */
static INT WPRINTF_ParseFormatA(uc_engine* uc, LPCSTR format, WPRINTF_FORMAT *res)
{
    LPCSTR p = format;

    res->flags = 0;
    res->width = 0;
    res->precision = 0;
    if (*p == '-') { res->flags |= WPRINTF_LEFTALIGN; p++; }
    if (*p == '#') { res->flags |= WPRINTF_PREFIX_HEX; p++; }
    if (*p == '0') { res->flags |= WPRINTF_ZEROPAD; p++; }
    while ((*p >= '0') && (*p <= '9'))  /* width field */
    {
        res->width = res->width * 10 + *p - '0';
        p++;
    }
    if (*p == '.')  /* precision field */
    {
        p++;
        while ((*p >= '0') && (*p <= '9'))
        {
            res->precision = res->precision * 10 + *p - '0';
            p++;
        }
    }
    if (*p == 'l') { res->flags |= WPRINTF_LONG; p++; }
    else if (*p == 'h') { res->flags |= WPRINTF_SHORT; p++; }
    else if (*p == 'w') { res->flags |= WPRINTF_WIDE; p++; }
    else if (*p == 'I')
    {
        if (p[1] == '6' && p[2] == '4') { res->flags |= WPRINTF_I64; p += 3; }
        else if (p[1] == '3' && p[2] == '2') { p += 3; }
        else { res->flags |= WPRINTF_INTPTR; p++; }
    }

    switch(*p)
    {
    case 'c':
    {
        res->type = (res->flags & WPRINTF_LONG) ? WPR_WCHAR : WPR_CHAR;
        break;
    }
    case 'C':
    {
        res->type = (res->flags & WPRINTF_SHORT) ? WPR_CHAR : WPR_WCHAR;
        break;
    }
    case 'd': __fallthrough;
    case 'i':
    {
        res->type = WPR_SIGNED;
        break;
    }
    case 's':
    {
        res->type = (res->flags & (WPRINTF_LONG | WPRINTF_WIDE)) ? WPR_WSTRING : WPR_STRING;
        break;
    }
    case 'S':
    {
        res->type = (res->flags & (WPRINTF_SHORT | WPRINTF_WIDE)) ? WPR_STRING : WPR_WSTRING;
        break;
    }
    case 'u':
    {
        res->type = WPR_UNSIGNED;
        break;
    }
    case 'p':
    {
        res->width = 2 * sizeof(void*);
        res->flags |= WPRINTF_ZEROPAD | WPRINTF_INTPTR;
        __fallthrough;/* fall through */
    }
    case 'X':
    {
        res->flags |= WPRINTF_UPPER_HEX;
        __fallthrough;/* fall through */
    }
    case 'x':
    {
        res->type = WPR_HEXA;
        break;
    }
    default: /* unknown format char */
    {
        res->type = WPR_UNKNOWN;
        p--;  /* print format as normal char */
        break;
    }
    }
    return (INT)(p - format) + 1;
}


/***********************************************************************
 *           WPRINTF_ParseFormatW
 *
 * Parse a format specification. A format specification has the form:
 *
 * [-][#][0][width][.precision]type
 *
 * Return value is the length of the format specification in characters.
 */
static INT WPRINTF_ParseFormatW(uc_engine* uc, LPCWSTR format, WPRINTF_FORMAT *res)
{
    LPCWSTR p = format;

    res->flags = 0;
    res->width = 0;
    res->precision = 0;
    if (*p == '-') { res->flags |= WPRINTF_LEFTALIGN; p++; }
    if (*p == '#') { res->flags |= WPRINTF_PREFIX_HEX; p++; }
    if (*p == '0') { res->flags |= WPRINTF_ZEROPAD; p++; }
    while ((*p >= '0') && (*p <= '9'))  /* width field */
    {
        res->width = res->width * 10 + *p - '0';
        p++;
    }
    if (*p == '.')  /* precision field */
    {
        p++;
        while ((*p >= '0') && (*p <= '9'))
        {
            res->precision = res->precision * 10 + *p - '0';
            p++;
        }
    }
    if (*p == 'l') { res->flags |= WPRINTF_LONG; p++; }
    else if (*p == 'h') { res->flags |= WPRINTF_SHORT; p++; }
    else if (*p == 'w') { res->flags |= WPRINTF_WIDE; p++; }
    else if (*p == 'I')
    {
        if (p[1] == '6' && p[2] == '4') { res->flags |= WPRINTF_I64; p += 3; }
        else if (p[1] == '3' && p[2] == '2') { p += 3; }
        else { res->flags |= WPRINTF_INTPTR; p++; }
    }
    switch(*p)
    {
    case 'c':
    {
        res->type = (res->flags & WPRINTF_SHORT) ? WPR_CHAR : WPR_WCHAR;
        break;
    }
    case 'C':
    {
        res->type = (res->flags & WPRINTF_LONG) ? WPR_WCHAR : WPR_CHAR;
        break;
    }
    case 'd': __fallthrough;
    case 'i':
    {
        res->type = WPR_SIGNED;
        break;
    }
    case 's':
    {
        res->type = ((res->flags & WPRINTF_SHORT) && !(res->flags & WPRINTF_WIDE)) ? WPR_STRING : WPR_WSTRING;
        break;
    }
    case 'S':
    {
        res->type = (res->flags & (WPRINTF_LONG | WPRINTF_WIDE)) ? WPR_WSTRING : WPR_STRING;
        break;
    }
    case 'u':
    {
        res->type = WPR_UNSIGNED;
        break;
    }
    case 'p':
    {
        res->width = 2 * sizeof(void*);
        res->flags |= WPRINTF_ZEROPAD | WPRINTF_INTPTR;
        __fallthrough;/* fall through */
    }
    case 'X':
    {
        res->flags |= WPRINTF_UPPER_HEX;
        __fallthrough;/* fall through */
    }
    case 'x':
    {
        res->type = WPR_HEXA;
        break;
    }
    default:
    {
        res->type = WPR_UNKNOWN;
        p--;  /* print format as normal char */
        break;
    }
    }
    return (INT)(p - format) + 1;
}


/***********************************************************************
 *           WPRINTF_GetLen
 */
static UINT WPRINTF_GetLen(uc_engine* uc, WPRINTF_FORMAT *format, WPRINTF_DATA *arg,
                            LPSTR number, UINT maxlen, BOOL dst_is_wide)
{
    UINT len;

    if (format->flags & WPRINTF_LEFTALIGN) format->flags &= ~WPRINTF_ZEROPAD;
    if (format->width > maxlen) format->width = maxlen;
    switch(format->type)
    {
    case WPR_CHAR: { return (format->precision = 1); }
    case WPR_WCHAR:
    {
        if (dst_is_wide) len = 1;
        else len = WideCharToMultiByte(CP_ACP, 0, &arg->wchar_view, 1, NULL, 0, NULL, NULL);
        return (format->precision = len);
    }
    case WPR_STRING:
    {
        if (!arg->lpcstr_view) arg->lpcstr_view = "(null)";
        if (dst_is_wide)
        {
            LPCSTR p = arg->lpcstr_view;
            for (len = 0; (!format->precision || len < format->precision) && *p; p++)
            {
                /* This isn't applicable for UTF-8 and UTF-7 */
                if (IsDBCSLeadByte(*p)) p++;
                len++;
                if (!*p) break;
            }
        }
        else
        {
            for (len = 0; !format->precision || (len < format->precision); len++)
                if (!*(arg->lpcstr_view + len)) break;
        }
        if (len > maxlen) len = maxlen;
        return (format->precision = len);
    }
    case WPR_WSTRING:
    {
        if (!arg->lpcwstr_view) arg->lpcwstr_view = L"(null)";
        if (dst_is_wide)
        {
            for (len = 0; !format->precision || (len < format->precision); len++)
                if (!*(arg->lpcwstr_view + len)) break;
        }
        else
        {
            LPCWSTR p = arg->lpcwstr_view;
            for (len = 0; (!format->precision || len < format->precision) && *p; p++)
                len += WideCharToMultiByte(CP_ACP, 0, p, 1, NULL, 0, NULL, NULL);
            if (format->precision && len > format->precision) len = format->precision;
        }
        if (len > maxlen) len = maxlen;
        return (format->precision = len);
    }
    case WPR_SIGNED: __fallthrough;
    case WPR_UNSIGNED: __fallthrough;
    case WPR_HEXA:
    {
        const char *digits = (format->flags & WPRINTF_UPPER_HEX) ? "0123456789ABCDEF" : "0123456789abcdef";
        ULONGLONG num = arg->int_view;
        int base = format->type == WPR_HEXA ? 16 : 10;
        char buffer[20], *p = buffer, *dst = number;

        if (format->type == WPR_SIGNED && arg->int_view < 0)
        {
            *dst++ = '-';
            num = -arg->int_view;
        }
        if (format->flags & WPRINTF_INTPTR) num = (UINT_PTR)num;
        else if (!(format->flags & WPRINTF_I64)) num = (UINT)num;

        do
        {
            *p++ = digits[num % base];
            num /= base;
        } while (num);
        while (p > buffer) *dst++ = *(--p);
        *dst = 0;
        len = dst - number;
        break;
    }
    default:
        return 0;
    }
    if (len > maxlen) { len = maxlen; }
    if (format->precision < len) { format->precision = len; }
    if (format->precision > maxlen) { format->precision = maxlen; }
    if ((format->flags & WPRINTF_ZEROPAD) && (format->width > format->precision)) { format->precision = format->width; }
    if (format->flags & WPRINTF_PREFIX_HEX) { len += 2; }
    return len;
}


/***********************************************************************
 *           wvsnprintfA   (internal)
 */
static INT InternalwvsnprintfA(uc_engine* uc, LPSTR buffer, UINT maxlen, LPCSTR spec, va_list args)
{
    WPRINTF_FORMAT format;
    LPSTR p = buffer;
    UINT i, len, sign;
    CHAR number[21]; /* 64bit number can be 18446744073709551616 which is 20 chars. and a \0 */
    WPRINTF_DATA argData;

    //TRACE("%p %u %s\n", buffer, maxlen, debugstr_a(spec));

    while (*spec && (maxlen > 1))
    {
        if (*spec != '%') { *p++ = *spec++; maxlen--; continue; }
        spec++;
        if (*spec == '%') { *p++ = *spec++; maxlen--; continue; }
        spec += WPRINTF_ParseFormatA(uc, spec, &format);

        switch(format.type)
        {
        case WPR_WCHAR:
        {
            crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.wchar_view, sizeof(int));
            //argData.wchar_view = (WCHAR)va_arg(args, int);
            break;
        }
        case WPR_CHAR:
        {
            crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.char_view, sizeof(int));
            //argData.char_view = (CHAR)va_arg(args, int);
            break;
        }
        case WPR_STRING:
        {
            crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.lpcstr_view, sizeof(LPCSTR));
            //argData.lpcstr_view = va_arg(args, LPCSTR);
            break;
        }
        case WPR_WSTRING:
        {
            crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.lpcwstr_view, sizeof(LPCWSTR));
            //argData.lpcwstr_view = va_arg(args, LPCWSTR);
            break;
        }
        case WPR_HEXA: __fallthrough;
        case WPR_SIGNED: __fallthrough;
        case WPR_UNSIGNED:
        {
            if (format.flags & WPRINTF_INTPTR)
            { 
                crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.int_view, sizeof(INT_PTR));
                //argData.int_view = va_arg(args, INT_PTR);
            }
            else if (format.flags & WPRINTF_I64)
            { 
                crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.int_view, sizeof(LONGLONG));
                //argData.int_view = va_arg(args, LONGLONG); 
            }
            else 
            { 
                crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.int_view, sizeof(INT));
                //argData.int_view = va_arg(args, INT);
            }
            break;
        }
        default:
        {
            argData.wchar_view = 0;
            break;
        }
        }

        len = WPRINTF_GetLen(uc, &format, &argData, number, maxlen - 1, FALSE );
        sign = 0;
        if (!(format.flags & WPRINTF_LEFTALIGN))
        {
            for (i = format.precision; i < format.width; i++, maxlen--)
            {
                *p++ = ' ';
            }
        }
        switch(format.type)
        {
        case WPR_WCHAR:
        {
            CHAR mb[5];
            if (WideCharToMultiByte(CP_ACP, 0, &argData.wchar_view, 1, mb, sizeof(mb), NULL, NULL))
            {
                memcpy(p, mb, len);
                p += len;
            }
            break;
        }
        case WPR_CHAR:
        {
            *p++ = argData.char_view;
            break;
        }
        case WPR_STRING:
        {
            memcpy(p, argData.lpcstr_view, len);
            p += len;
            break;
        }
        case WPR_WSTRING:
        {
            LPCWSTR ptr = argData.lpcwstr_view;
            for (i = 0; i < len; ptr++)
            {
                CHAR mb[5]; /* 5 is MB_LEN_MAX */
                int ret = WideCharToMultiByte(CP_ACP, 0, ptr, 1, mb, sizeof(mb), NULL, NULL);
                if (ret > len - i) ret = len - i;
                i += ret;
                memcpy(p, mb, ret);
                p += ret;
            }
            break;
        }
        case WPR_HEXA:
        {
            if ((format.flags & WPRINTF_PREFIX_HEX) && (maxlen > 3))
            {
                *p++ = '0';
                *p++ = (format.flags & WPRINTF_UPPER_HEX) ? 'X' : 'x';
                maxlen -= 2;
                len -= 2;
            }
            __fallthrough;/* fall through */
        }
        case WPR_SIGNED:
        {
            /* Transfer the sign now, just in case it will be zero-padded*/
            if (number[0] == '-')
            {
                *p++ = '-';
                sign = 1;
            }
            __fallthrough;/* fall through */
        }
        case WPR_UNSIGNED:
        {
            for (i = len; i < format.precision; i++, maxlen--)
            {
                *p++ = '0';
            }
            memcpy(p, number + sign, len - sign);
            p += len - sign;
            break;
        }
        case WPR_UNKNOWN: { continue; }
        }
        if (format.flags & WPRINTF_LEFTALIGN)
        {
            for (i = format.precision; i < format.width; i++, maxlen--)
            {
                *p++ = ' ';
            }
        }
        maxlen -= len;
    }
    *p = 0;
    //TRACE("%s\n",debugstr_a(buffer));

    return (maxlen > 1) ? (INT)(p - buffer) : -1;
}


/***********************************************************************
 *           wvsnprintfW   (internal)
 */
static INT InternalwvsnprintfW(uc_engine* uc, LPWSTR buffer, UINT maxlen, LPCWSTR spec, va_list args)
{
    WPRINTF_FORMAT format;
    LPWSTR p = buffer;
    UINT i, len, sign;
    CHAR number[21]; /* 64bit number can be 18446744073709551616 which is 20 chars. and a \0 */
    WPRINTF_DATA argData;

    //TRACE("%p %u %s\n", buffer, maxlen, debugstr_w(spec));

    while (*spec && (maxlen > 1))
    {
        if (*spec != '%') { *p++ = *spec++; maxlen--; continue; }
        spec++;
        if (*spec == '%') { *p++ = *spec++; maxlen--; continue; }
        spec += WPRINTF_ParseFormatW(uc, spec, &format);

        switch(format.type)
        {
        case WPR_WCHAR:
        {
            crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.wchar_view, sizeof(int));
            //argData.wchar_view = (WCHAR)va_arg(args, int);
            break;
        }
        case WPR_CHAR:
        {
            crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.char_view, sizeof(int));
            //argData.char_view = (CHAR)va_arg(args, int);
            break;
        }
        case WPR_STRING:
        {
            crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.lpcstr_view, sizeof(LPCSTR));
            //argData.lpcstr_view = va_arg(args, LPCSTR);
            break;
        }
        case WPR_WSTRING:
        {
            crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.lpcwstr_view, sizeof(LPCWSTR));
            //argData.lpcwstr_view = va_arg(args, LPCWSTR);
            break;
        }
        case WPR_HEXA: __fallthrough;
        case WPR_SIGNED: __fallthrough;
        case WPR_UNSIGNED:
        {
            if (format.flags & WPRINTF_INTPTR) 
            { 
                crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.int_view, sizeof(INT_PTR));
                //argData.int_view = va_arg(args, INT_PTR);
            }
            else if (format.flags & WPRINTF_I64)
            { 
                crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.int_view, sizeof(LONGLONG));
                //argData.int_view = va_arg(args, LONGLONG); 
            }
            else 
            { 
                crt_va_arg_func(uc, (PDWORD_PTR)&args, &argData.int_view, sizeof(INT));
                //argData.int_view = va_arg(args, INT);
            }
            break;
        }
        default:
        {
            argData.wchar_view = 0;
            break;
        }
        }

        len = WPRINTF_GetLen(uc, &format, &argData, number, maxlen - 1, TRUE);
        sign = 0;
        if (!(format.flags & WPRINTF_LEFTALIGN))
        {
            for (i = format.precision; i < format.width; i++, maxlen--)
            {
                *p++ = ' ';
            }
        }

        switch (format.type)
        {
        case WPR_WCHAR:
        {
            *p++ = argData.wchar_view;
            break;
        }
        case WPR_CHAR:
        {
            WCHAR wc;
            if (!IsDBCSLeadByte((BYTE)argData.char_view) &&
                MultiByteToWideChar(CP_ACP, 0, &argData.char_view, 1, &wc, 1) > 0)
            {
                *p++ = wc;
            }
            else
            {
                *p++ = 0;
            }
            break;
        }
        case WPR_STRING:
        {
            LPCSTR ptr = argData.lpcstr_view;
            for (i = 0; i < len; i++)
            {
                WCHAR buf[2]; /* for LeadByte + NUL case, we need 2 WCHARs. */
                int ret, mb_len = IsDBCSLeadByte(*ptr) ? 2 : 1;
                ret = MultiByteToWideChar(CP_ACP, 0, ptr, mb_len, buf, ARRAY_SIZE(buf));
                *p++ = buf[ret - 1];
                ptr += mb_len;
            }
            break;
        }
        case WPR_WSTRING:
        {
            if (len)
            {
                memcpy(p, argData.lpcwstr_view, len * sizeof(WCHAR));
            }
            p += len;
            break;
        }
        case WPR_HEXA:
        {
            if ((format.flags & WPRINTF_PREFIX_HEX) && (maxlen > 3))
            {
                *p++ = '0';
                *p++ = (format.flags & WPRINTF_UPPER_HEX) ? 'X' : 'x';
                maxlen -= 2;
                len -= 2;
            }
            __fallthrough; /* fall through */
        }
        case WPR_SIGNED:
        {
            /* Transfer the sign now, just in case it will be zero-padded*/
            if (number[0] == '-')
            {
                *p++ = '-';
                sign = 1;
            }
            __fallthrough;/* fall through */
        }
        case WPR_UNSIGNED:
        {
            for (i = len; i < format.precision; i++, maxlen--)
            {
                *p++ = '0';
            }

            for (i = sign; i < len; i++)
            {
                *p++ = (BYTE)number[i];
            }
            break;
        }
        case WPR_UNKNOWN: { continue; }
        }

        if (format.flags & WPRINTF_LEFTALIGN)
        {
            for (i = format.precision; i < format.width; i++, maxlen--)
            {
                *p++ = ' ';
            }
        }
        maxlen -= len;
    }
    *p = 0;
    //TRACE("%s\n",debugstr_w(buffer));

    return (maxlen > 1) ? (INT)(p - buffer) : -1;
}


/***********************************************************************
 *           wvsprintfA   (USER32.@)
 */
INT CustomWvsprintfA(uc_engine* uc, LPSTR buffer, LPCSTR spec, va_list args)
{
    INT res = InternalwvsnprintfA(uc, buffer, 1024, spec, args);

    return ( res == -1 ) ? 1024 : res;
}


/***********************************************************************
 *           wvsprintfW   (USER32.@)
 */
INT CustomWvsprintfW(uc_engine* uc, LPWSTR buffer, LPCWSTR spec, va_list args)
{
    INT res = InternalwvsnprintfW(uc, buffer, 1024, spec, args);

    return ( res == -1 ) ? 1024 : res;
}


/***********************************************************************
 *           wsprintfA   (USER32.@)
 */
INT CustomWsprintfA(uc_engine* uc, LPSTR buffer, LPCSTR spec, ...)
{
    va_list valist;
    INT res;

    va_start( valist, spec );
    res = InternalwvsnprintfA(uc, buffer, 1024, spec, valist);
    va_end( valist );

    return ( res == -1 ) ? 1024 : res;
}


/***********************************************************************
 *           wsprintfW   (USER32.@)
 */
INT CustomWsprintfW(uc_engine* uc, LPWSTR buffer, LPCWSTR spec, ...)
{
    va_list valist;
    INT res;

    va_start( valist, spec );
    res = InternalwvsnprintfW(uc, buffer, 1024, spec, valist);
    va_end( valist );

    return ( res == -1 ) ? 1024 : res;
}