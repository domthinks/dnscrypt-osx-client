//
//  DNSCrypt.h
//  DNSCrypt
//
//  Created by OpenDNS, Inc. on 8/11/11.
//  Copyright (c) 2011 OpenDNS, Inc. All rights reserved.
//

#import <PreferencePanes/PreferencePanes.h>
#import <WebKit/WebKit.h>

#define kDNSCRYPT_PACKAGE_VERSION @"0.17"

#define kDNSCRYPT_PREFPANE_APP_PATH @"/Library/PreferencePanes/DNSCrypt.prefPane"
#define kDNSCRYPT_USR_BASE_DIR kDNSCRYPT_PREFPANE_APP_PATH @"/Contents/Resources/usr"
#define kDNSCRIPT_BIN_BASE_DIR kDNSCRYPT_USR_BASE_DIR @"/bin"
#define kDNSCRIPT_SCRIPTS_BASE_DIR kDNSCRYPT_USR_BASE_DIR @"/scripts"
#define kDNSCRYPT_VAR_BASE_DIR @"/Library/Application Support/DNSCrypt"
#define kDNSCRYPT_CONTROL_DIR kDNSCRYPT_VAR_BASE_DIR @"/control"

#define kDNSCRYPT_QUERY_LOG_FILE @"/var/log/dnscrypt-query.log"
#define kDNSCRYPT_BLACKLIST_IPS_TMP_FILE kDNSCRYPT_CONTROL_DIR @"/blacklist-ips.tmp"
#define kDNSCRYPT_BLACKLIST_DOMAINS_TMP_FILE kDNSCRYPT_CONTROL_DIR @"/blacklist-domains.tmp"
#define kDNSCRYPT_EXCEPTIONS_TMP_FILE kDNSCRYPT_CONTROL_DIR @"/exceptions.tmp"

#define kOPENDNS_URL @"http://www.opendns.com"

#define kBUNDLE_IDENTIFIER @"com.opendns.osx.DNSCrypt"

#define kREFRESH_DELAY 2.0
#define kCHECKBOXES_AFTER_CHANGE_DELAY 8.0
#define kMAX_TRIES_AFTER_CHANGE (30 / kREFRESH_DELAY)

typedef enum {
    kDNS_CONFIGURATION_UNKNOWN, kDNS_CONFIGURATION_VANILLA, kDNS_CONFIGURATION_LOCALHOST, kDNS_CONFIGURATION_OPENDNS
} DNSConfigurationState;

@interface DNSCrypt : NSPreferencePane {
    AuthorizationRef auth;
}
@property (nonatomic, retain) IBOutlet NSTabView *tabView;
@property (nonatomic, retain) IBOutlet NSTabViewItem *aboutTabViewItem;
@property (nonatomic, retain) IBOutlet NSTabViewItem *releaseNotesTabViewItem;

@property (nonatomic, retain) IBOutlet NSButton *dnscryptButton;
@property (nonatomic, retain) IBOutlet NSButton *opendnsButton;
@property (nonatomic, retain) IBOutlet NSButton *familyShieldButton;
@property (nonatomic, retain) IBOutlet NSButton *fallbackButton;

@property (nonatomic, retain) IBOutlet NSTextField *currentResolverTextField;
@property (nonatomic, retain) IBOutlet NSImageView *statusImageView;
@property (nonatomic, retain) IBOutlet NSTextField *statusText;
@property (nonatomic, retain) IBOutlet WebView *previewNotesWebView;
@property (nonatomic, retain) IBOutlet WebView *releaseNotesWebView;
@property (nonatomic, retain) IBOutlet WebView *feedbackWebView;
@property (nonatomic, retain) IBOutlet WebView *aboutWebView;
@property (nonatomic, retain) IBOutlet NSTextFieldCell *staticResolversTextField;
@property (nonatomic, retain) IBOutlet NSButton *parentalControlsButton;
@property (nonatomic, retain) IBOutlet NSButtonCell *queryLoggingButton;
@property (nonatomic, retain) IBOutlet NSButton *lockinButton;
@property (nonatomic, retain) IBOutlet NSTextField *blacklistIPsTextField;
@property (nonatomic, retain) IBOutlet NSTextField *blacklistDomainsTextField;
@property (nonatomic, retain) IBOutlet NSTextField *exceptionsTextField;
@property (nonatomic, retain) IBOutlet WebView *helpWebView;

- (void) mainViewDidLoad;

- (IBAction)dnscryptButtonPressed:(NSButton *)sender;
- (IBAction)opendnsButtonPressed:(NSButton *)sender;
- (IBAction)familyShieldButtonPressed:(NSButton *)sender;
- (IBAction)fallbackButtonPressed:(NSButton *)sender;

- (IBAction)openDNSLinkPushed:(NSButton *)sender;
- (IBAction)uninstallPushed:(NSButton *)sender;
- (IBAction)staticResolversTextFieldChanged:(NSTextField *)sender;
- (IBAction)parentalControlsButtonPressed:(NSButtonCell *)sender;
- (IBAction)queryLoggingButtonPressed:(NSButtonCell *)sender;
- (IBAction)viewLogButtonPushed:(NSButton *)sender;
- (IBAction)lockinButtonPressed:(NSButton *)sender;
- (IBAction)blacklistIPsUpdated:(NSTextField *)sender;
- (IBAction)blacklistDomainsUpdated:(NSTextField *)sender;
- (IBAction)exceptionsUpdated:(NSTextField *)sender;
- (IBAction)helpButtonPressed:(NSButton *)sender;

@end
