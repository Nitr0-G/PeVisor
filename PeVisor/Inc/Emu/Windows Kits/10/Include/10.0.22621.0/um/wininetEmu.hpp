/*
 ███▄ ▄███▓▄▄▄      ██▀███  ██▓█    ██  ██████     ▄▄▄      ██ ▄█▄▄▄          ███▄    █ ██▄▄▄█████▓██▀███  ▒█████   ▄████ 
▓██▒▀█▀ ██▒████▄   ▓██ ▒ ██▓██▒██  ▓██▒██    ▒    ▒████▄    ██▄█▒████▄        ██ ▀█   █▓██▓  ██▒ ▓▓██ ▒ ██▒██▒  ██▒██▒ ▀█▒
▓██    ▓██▒██  ▀█▄ ▓██ ░▄█ ▒██▓██  ▒██░ ▓██▄      ▒██  ▀█▄ ▓███▄▒██  ▀█▄     ▓██  ▀█ ██▒██▒ ▓██░ ▒▓██ ░▄█ ▒██░  ██▒██░▄▄▄░
▒██    ▒██░██▄▄▄▄██▒██▀▀█▄ ░██▓▓█  ░██░ ▒   ██▒   ░██▄▄▄▄██▓██ █░██▄▄▄▄██    ▓██▒  ▐▌██░██░ ▓██▓ ░▒██▀▀█▄ ▒██   ██░▓█  ██▓
▒██▒   ░██▒▓█   ▓██░██▓ ▒██░██▒▒█████▓▒██████▒▒    ▓█   ▓██▒██▒ █▓█   ▓██▒   ▒██░   ▓██░██░ ▒██▒ ░░██▓ ▒██░ ████▓▒░▒▓███▀▒
░ ▒░   ░  ░▒▒   ▓▒█░ ▒▓ ░▒▓░▓ ░▒▓▒ ▒ ▒▒ ▒▓▒ ▒ ░    ▒▒   ▓▒█▒ ▒▒ ▓▒▒   ▓▒█░   ░ ▒░   ▒ ▒░▓   ▒ ░░  ░ ▒▓ ░▒▓░ ▒░▒░▒░ ░▒   ▒ 
░  ░      ░ ▒   ▒▒ ░ ░▒ ░ ▒░▒ ░░▒░ ░ ░░ ░▒  ░ ░     ▒   ▒▒ ░ ░▒ ▒░▒   ▒▒ ░   ░ ░░   ░ ▒░▒ ░   ░     ░▒ ░ ▒░ ░ ▒ ▒░  ░   ░ 
░      ░    ░   ▒    ░░   ░ ▒ ░░░░ ░ ░░  ░  ░       ░   ▒  ░ ░░ ░ ░   ▒         ░   ░ ░ ▒ ░ ░       ░░   ░░ ░ ░ ▒ ░ ░   ░ 
       ░        ░  ░  ░     ░    ░          ░           ░  ░  ░       ░  ░            ░ ░            ░        ░ ░       ░ 
                                                                                                                          

*/
#pragma once
#include <KNSoft/NDK/NDK.h>
#include "unicorn/unicorn.h"
#include "Emu/EmuUtils.hpp"
#include <string>
#include <vector>
#include <wininet.h>

namespace EmuApi {
    void EmuInternetTimeFromSystemTimeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetTimeFromSystemTimeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetTimeToSystemTimeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetTimeToSystemTimeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetCrackUrlA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetCrackUrlW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetCreateUrlA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetCreateUrlW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetCanonicalizeUrlA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetCanonicalizeUrlW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetCombineUrlA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetCombineUrlW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetOpenA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetOpenW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetCloseHandle(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetConnectA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetConnectW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetOpenUrlA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetOpenUrlW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetReadFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetReadFileExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetReadFileExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetFilePointer(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetWriteFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetQueryDataAvailable(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetFindNextFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetFindNextFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetQueryOptionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetQueryOptionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetOptionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetOptionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetOptionExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetOptionExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetLockRequestFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetUnlockRequestFile(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGetLastResponseInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGetLastResponseInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetStatusCallbackA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetStatusCallbackW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpFindFirstFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpFindFirstFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpGetFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpGetFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpPutFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpPutFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpGetFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpPutFileEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpDeleteFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpDeleteFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpRenameFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpRenameFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpOpenFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpOpenFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpCreateDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpCreateDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpRemoveDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpRemoveDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpSetCurrentDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpSetCurrentDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpGetCurrentDirectoryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpGetCurrentDirectoryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpCommandA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpCommandW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFtpGetFileSize(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGopherCreateLocatorA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGopherCreateLocatorW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGopherGetLocatorTypeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGopherGetLocatorTypeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGopherFindFirstFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGopherFindFirstFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGopherOpenFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGopherOpenFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGopherGetAttributeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGopherGetAttributeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpOpenRequestA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpOpenRequestW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpAddRequestHeadersA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpAddRequestHeadersW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpSendRequestA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpSendRequestW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpSendRequestExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpSendRequestExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpEndRequestA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpEndRequestW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpQueryInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpQueryInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetCookieA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetCookieW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGetCookieA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGetCookieW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetCookieExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetCookieExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGetCookieExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGetCookieExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetFreeCookies(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGetCookieEx2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetCookieEx2(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetAttemptConnect(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetCheckConnectionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetCheckConnectionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetAuthNotifyCallback(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuResumeSuspendedDownload(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetErrorDlg(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetConfirmZoneCrossingA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetConfirmZoneCrossingW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateUrlCacheEntryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateUrlCacheEntryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCommitUrlCacheEntryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCommitUrlCacheEntryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuRetrieveUrlCacheEntryFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuRetrieveUrlCacheEntryFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuUnlockUrlCacheEntryFileA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuUnlockUrlCacheEntryFileW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuRetrieveUrlCacheEntryStreamA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuRetrieveUrlCacheEntryStreamW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuReadUrlCacheEntryStream(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuReadUrlCacheEntryStreamEx(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuUnlockUrlCacheEntryStream(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetUrlCacheEntryInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetUrlCacheEntryInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstUrlCacheGroup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindNextUrlCacheGroup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetUrlCacheGroupAttributeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetUrlCacheGroupAttributeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetUrlCacheGroupAttributeA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetUrlCacheGroupAttributeW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetUrlCacheEntryInfoExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuGetUrlCacheEntryInfoExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetUrlCacheEntryInfoA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetUrlCacheEntryInfoW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateUrlCacheGroup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDeleteUrlCacheGroup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetUrlCacheEntryGroupA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuSetUrlCacheEntryGroupW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstUrlCacheEntryExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstUrlCacheEntryExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindNextUrlCacheEntryExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindNextUrlCacheEntryExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstUrlCacheEntryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindFirstUrlCacheEntryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindNextUrlCacheEntryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindNextUrlCacheEntryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuFindCloseUrlCache(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDeleteUrlCacheEntryA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDeleteUrlCacheEntryW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetDialA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetDialW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetHangUp(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGoOnlineA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGoOnlineW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetAutodial(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetAutodialHangup(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGetConnectedState(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGetConnectedStateExA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGetConnectedStateExW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDeleteWpadCacheForNetworks(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetInitializeAutoProxyDll(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuDetectAutoProxyUrl(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuCreateMD5SSOHash(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetDialStateA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetDialStateW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetPerSiteCookieDecisionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetSetPerSiteCookieDecisionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGetPerSiteCookieDecisionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetGetPerSiteCookieDecisionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetClearAllPerSiteCookieDecisions(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetEnumPerSiteCookieDecisionA(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuInternetEnumPerSiteCookieDecisionW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuPrivacySetZonePreferenceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuPrivacyGetZonePreferenceW(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);
    void EmuHttpIsHostHstsEnabled(uc_engine* uc, DWORD_PTR address, size_t size, void* user_data);

}


/* number of functions: 171*/
