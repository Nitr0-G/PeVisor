#pragma once

#include "./MinDef.h"

EXTERN_C_START

/* ntifs.h */
#define SeLengthSid( Sid ) (8 + (4 * ((SID*)Sid)->SubAuthorityCount))

/* ntifs.h */
typedef struct _SE_EXPORTS
{
    //
    // Privilege values
    //
    LUID    SeCreateTokenPrivilege;
    LUID    SeAssignPrimaryTokenPrivilege;
    LUID    SeLockMemoryPrivilege;
    LUID    SeIncreaseQuotaPrivilege;
    LUID    SeUnsolicitedInputPrivilege;
    LUID    SeTcbPrivilege;
    LUID    SeSecurityPrivilege;
    LUID    SeTakeOwnershipPrivilege;
    LUID    SeLoadDriverPrivilege;
    LUID    SeCreatePagefilePrivilege;
    LUID    SeIncreaseBasePriorityPrivilege;
    LUID    SeSystemProfilePrivilege;
    LUID    SeSystemtimePrivilege;
    LUID    SeProfileSingleProcessPrivilege;
    LUID    SeCreatePermanentPrivilege;
    LUID    SeBackupPrivilege;
    LUID    SeRestorePrivilege;
    LUID    SeShutdownPrivilege;
    LUID    SeDebugPrivilege;
    LUID    SeAuditPrivilege;
    LUID    SeSystemEnvironmentPrivilege;
    LUID    SeChangeNotifyPrivilege;
    LUID    SeRemoteShutdownPrivilege;

    //
    // Universally defined Sids
    //
    PSID  SeNullSid;
    PSID  SeWorldSid;
    PSID  SeLocalSid;
    PSID  SeCreatorOwnerSid;
    PSID  SeCreatorGroupSid;

    //
    // Nt defined Sids
    //
    PSID  SeNtAuthoritySid;
    PSID  SeDialupSid;
    PSID  SeNetworkSid;
    PSID  SeBatchSid;
    PSID  SeInteractiveSid;
    PSID  SeLocalSystemSid;
    PSID  SeAliasAdminsSid;
    PSID  SeAliasUsersSid;
    PSID  SeAliasGuestsSid;
    PSID  SeAliasPowerUsersSid;
    PSID  SeAliasAccountOpsSid;
    PSID  SeAliasSystemOpsSid;
    PSID  SeAliasPrintOpsSid;
    PSID  SeAliasBackupOpsSid;

    //
    // New Sids defined for NT5
    //
    PSID  SeAuthenticatedUsersSid;
    PSID  SeRestrictedSid;
    PSID  SeAnonymousLogonSid;

    //
    // New Privileges defined for NT5
    //
    LUID  SeUndockPrivilege;
    LUID  SeSyncAgentPrivilege;
    LUID  SeEnableDelegationPrivilege;

    //
    // New Sids defined for post-Windows 2000
    //
    PSID  SeLocalServiceSid;
    PSID  SeNetworkServiceSid;

    //
    // New Privileges defined for post-Windows 2000
    //
    LUID  SeManageVolumePrivilege;
    LUID  SeImpersonatePrivilege;
    LUID  SeCreateGlobalPrivilege;

    //
    // New Privileges defined for post Windows Server 2003
    //
    LUID  SeTrustedCredManAccessPrivilege;
    LUID  SeRelabelPrivilege;
    LUID  SeIncreaseWorkingSetPrivilege;
    LUID  SeTimeZonePrivilege;
    LUID  SeCreateSymbolicLinkPrivilege;

    //
    // New Sids defined for post Windows Server 2003
    //
    PSID  SeIUserSid;

    //
    // Mandatory Sids, ordered lowest to highest.
    //
    PSID SeUntrustedMandatorySid;
    PSID SeLowMandatorySid;
    PSID SeMediumMandatorySid;
    PSID SeHighMandatorySid;
    PSID SeSystemMandatorySid;
    PSID SeOwnerRightsSid;

    //
    // Package/Capability Sids.
    //
    PSID SeAllAppPackagesSid;
    PSID SeUserModeDriversSid;

    //
    // Process Trust Sids.
    //
    PSID SeProcTrustWinTcbSid;

    //
    // Trusted Installer SID.
    //
    PSID SeTrustedInstallerSid;

    //
    // New Privileges defined for Windows 10
    //
    LUID  SeDelegateSessionUserImpersonatePrivilege;

    //
    // App Silo SID
    //
    PSID SeAppSiloSid;

    //
    // App Silo Volume Root Minimal Capability SID
    //
    PSID SeAppSiloVolumeRootMinimalCapabilitySid;

    //
    // App Silo Users Minimal Capability SID
    //
    PSID SeAppSiloProfilesRootMinimalCapabilitySid;

    //
    // App Silo Prompt Access Capability SID
    //
    PSID SeAppSiloPromptForAccessCapabilitySid;

    //
    // App Silo Access To Publisher Directory Capability SID
    //
    PSID SeAppSiloAccessToPublisherDirectoryCapabilitySid;
} SE_EXPORTS, *PSE_EXPORTS;

EXTERN_C_END
