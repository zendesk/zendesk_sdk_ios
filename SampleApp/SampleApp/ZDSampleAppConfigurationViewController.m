//
//  ZDSampleAppConfigurationViewController.m
//  SampleApp
//
//  Created by Zendesk on 11/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import "ZDSampleAppConfigurationViewController.h"

typedef NS_ENUM(NSUInteger, ZDSDKAuth) {
    ZDSDKAuthJwt,
    ZDSDKAuthAnonymous,
};

static NSString * const ZDSDKSampleAppDefaultsKey = @"ZDSDKSampleAppDefaultsKey";
static CGFloat const    ZDSDKPadding              = 15.f;

@interface ZDSampleAppConfigurationViewController ()

@property (nonatomic, strong) UILabel *urlDescription;
@property (nonatomic, strong) UILabel *authenticationOption;
@property (nonatomic, strong) UISegmentedControl *authenticationType;
@property (nonatomic, strong) UITextField *urlEntry;
@property (nonatomic, strong) UITextField *appIdEntry;
@property (nonatomic, strong) UITextField *clientIdEntry;
@property (nonatomic, strong) UITextField *userIdentifierEntry;
@property (nonatomic, strong) UITextField *nameEntry;
@property (nonatomic, strong) UITextField *emailEntry;
@property (nonatomic, strong) UITextField *externalIdEntry;

@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) UIView *scrollViewContent;

- (void) saveSettings:(NSDictionary *) settings;

@end



@implementation ZDSampleAppConfigurationViewController

@synthesize delegate;
@synthesize authenticationType;
@synthesize urlDescription, authenticationOption;
@synthesize urlEntry, appIdEntry, clientIdEntry, userIdentifierEntry, nameEntry, emailEntry, externalIdEntry;
@synthesize scrollView;


- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.scrollView = [[UIScrollView alloc] initWithFrame:self.view.frame];
    self.scrollViewContent = [[UIView alloc] initWithFrame:self.view.frame];
    
    [self.contentView addSubview:self.scrollView];
    [self.scrollView addSubview:self.scrollViewContent];
    self.scrollView.translatesAutoresizingMaskIntoConstraints = NO;
    
    [self.scrollView setContentSize:CGSizeMake(self.view.frame.size.width, self.view.frame.size.height)];
    
    // Do any additional setup after loading the view.
    self.title = @"SDK Sample Setup";
    
    //Set the done button up
    UIBarButtonItem *doneButton = [[UIBarButtonItem alloc] initWithTitle:@"Done"
                                                                   style:UIBarButtonItemStyleDone
                                                                  target:self
                                                                  action:@selector(doneButtonPressed)];
    self.navigationItem.rightBarButtonItem = doneButton;

    //Set the done button up
    UIBarButtonItem *clearButton = [[UIBarButtonItem alloc] initWithTitle:@"Clear"
                                                                    style:UIBarButtonItemStyleDone
                                                                   target:self
                                                                   action:@selector(clearButtonPressed)];
    self.navigationItem.leftBarButtonItem = clearButton;

    //Setup the entry elements

    // Url entry
    urlDescription = [self buildLableWithText:@"Enter your Zendesk URL like \'mysubdomain\' or an ip address like: \'http://192.168.1.10:80\'"];
    urlDescription.translatesAutoresizingMaskIntoConstraints = NO;
    urlDescription.preferredMaxLayoutWidth = CGRectGetWidth(self.view.frame) - ZDSDKPadding * 2;
    [self.scrollViewContent addSubview:urlDescription];

    urlEntry = [self buildTextFieldWithPlaceholder:@"URL to Zendesk"
                                      keyboardType:UIKeyboardTypeURL
                                         returnKey:UIReturnKeyNext
                                            andTag:1];
    [urlEntry setAccessibilityIdentifier:@"urlEntryField"];

    [self.scrollViewContent addSubview:urlEntry];

    // App ID entry
    appIdEntry = [self buildTextFieldWithPlaceholder:@"Application ID"
                                        keyboardType:UIKeyboardTypeAlphabet
                                           returnKey:UIReturnKeyNext
                                              andTag:2];
    [appIdEntry setAccessibilityIdentifier:@"appIdEntryField"];

    [self.scrollViewContent addSubview:appIdEntry];

    // Client ID entry
    clientIdEntry = [self buildTextFieldWithPlaceholder:@"Client ID"
                                           keyboardType:UIKeyboardTypeAlphabet
                                              returnKey:UIReturnKeyNext
                                                 andTag:3];
    [clientIdEntry setAccessibilityIdentifier:@"clientIdEntryField"];

    [self.scrollViewContent addSubview:clientIdEntry];

    // Url entry
    authenticationOption = [self buildLableWithText:@"Select authentication type"];
    authenticationOption.translatesAutoresizingMaskIntoConstraints = NO;
    authenticationOption.preferredMaxLayoutWidth = CGRectGetWidth(self.view.frame) - ZDSDKPadding * 2;
    [self.scrollViewContent addSubview:authenticationOption];

    // Authentication switch
    authenticationType = [[UISegmentedControl alloc] initWithItems:@[@"JWT",@"Anonymous"]];
    authenticationType.translatesAutoresizingMaskIntoConstraints = NO;
    authenticationType.selectedSegmentIndex = 1;
    authenticationType.tintColor = [UIColor colorWithRed:0.4705f green:0.6392f blue:0.0f alpha:1.0f];

    [authenticationType addTarget:self action:@selector(authTypeChanged:) forControlEvents: UIControlEventValueChanged];

    [authenticationType setAccessibilityIdentifier:@"authenticationType"];
    [self.scrollViewContent addSubview:authenticationType];


    // JWT authentication user identifier
    userIdentifierEntry = [self buildTextFieldWithPlaceholder:@"JWT user identifier"
                                                 keyboardType:UIKeyboardTypeAlphabet
                                                    returnKey:UIReturnKeyDone
                                                       andTag:4];
    [userIdentifierEntry setAccessibilityIdentifier:@"jwtUserIdField"];
    
    userIdentifierEntry.hidden = YES;

    [self.scrollViewContent addSubview:userIdentifierEntry];

    // Anonymous authentication name
    nameEntry = [self buildTextFieldWithPlaceholder:@"Name (optional)"
                                       keyboardType:UIKeyboardTypeAlphabet
                                          returnKey:UIReturnKeyNext
                                             andTag:INT16_MAX];
    [nameEntry setAccessibilityIdentifier:@"anonymousUserNameField"];
    nameEntry.hidden = NO;

    [self.scrollViewContent addSubview:nameEntry];

    // Anonymous authentication email
    emailEntry = [self buildTextFieldWithPlaceholder:@"Email (optional)"
                                        keyboardType:UIKeyboardTypeAlphabet
                                           returnKey:UIReturnKeyNext
                                              andTag:5];
    [emailEntry setAccessibilityIdentifier:@"anonymousEmailField"];
    emailEntry.hidden = NO;

    [self.scrollViewContent addSubview:emailEntry];

    // Anonymous authentication external ID
    externalIdEntry = [self buildTextFieldWithPlaceholder:@"External identifier (optional)"
                                             keyboardType:UIKeyboardTypeAlphabet
                                                returnKey:UIReturnKeyDone
                                                   andTag:6];
    [externalIdEntry setAccessibilityIdentifier:@"anonymousExternalIdField"];
    externalIdEntry.hidden = NO;

    [self.scrollViewContent addSubview:externalIdEntry];
    
  
    [self setupConstraints];
    
    
    NSData *storedConfig = [[NSUserDefaults standardUserDefaults] objectForKey:ZDSDKSampleAppDefaultsKey];
    
    if (storedConfig) {
        
        NSDictionary *config = (NSDictionary *)[NSKeyedUnarchiver unarchiveObjectWithData:storedConfig];
        if (config) {
        
            urlEntry.text = (NSString *)config[@"url"];
            appIdEntry.text = (NSString *)config[@"appId"];
            clientIdEntry.text = (NSString *)config[@"clientId"];
            userIdentifierEntry.text = (NSString *)config[@"userId"];
            nameEntry.text = (NSString *)config[@"name"];
            emailEntry.text = (NSString *)config[@"email"];
            externalIdEntry.text = (NSString *)config[@"externalId"];
            authenticationType.selectedSegmentIndex = [config[@"authType"] integerValue];
            [self authTypeChanged:authenticationType];
        }
    } else {
        [urlEntry becomeFirstResponder];
    }
    
    
    [self registerForKeyboardNotifications];
}


- (void) setupConstraints
{
    //auto layout for scroll view
    NSDictionary *views = NSDictionaryOfVariableBindings(scrollView);
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|[scrollView]|" options:0 metrics: 0 views:views]];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[scrollView]|" options:0 metrics: 0 views:views]];
    
    // auto layout for controls
     views = NSDictionaryOfVariableBindings(urlEntry,
                                            urlDescription,
                                            appIdEntry,
                                            clientIdEntry,
                                            authenticationOption,
                                            authenticationType,
                                            userIdentifierEntry,
                                            nameEntry,
                                            emailEntry,
                                            externalIdEntry);

    NSDictionary *metrics = @{@"padding":@(ZDSDKPadding), @"height":@(ZDSDKPadding * 2)};


    [self.scrollViewContent addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-padding-[urlDescription]-padding-|"
                                                                             options:NSLayoutFormatAlignmentMask
                                                                             metrics:metrics
                                                                               views:views]];


    [self.scrollViewContent addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|-[urlDescription(<=90)]-padding-[urlEntry(height)]-padding-[appIdEntry(height)]-padding-[clientIdEntry(height)]-padding-[authenticationOption(<=90)]-padding-[authenticationType(height)]"
                                                                             options:NSLayoutFormatAlignAllLeft | NSLayoutFormatAlignAllRight
                                                                             metrics:metrics
                                                                               views:views]];

    [self.scrollViewContent addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[authenticationType(height)]-padding-[userIdentifierEntry(height)]"
                                                                             options:NSLayoutFormatAlignAllLeft | NSLayoutFormatAlignAllRight
                                                                             metrics:metrics
                                                                               views:views]];

    [self.scrollViewContent addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:[authenticationType(height)]-padding-[nameEntry(height)]-padding-[emailEntry(height)]-padding-[externalIdEntry(height)]"
                                                                             options:NSLayoutFormatAlignAllLeft | NSLayoutFormatAlignAllRight
                                                                             metrics:metrics
                                                                               views:views]];
}


#pragma mark - Button Actions 


- (void) clearButtonPressed
{
    
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:ZDSDKSampleAppDefaultsKey];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    urlEntry.text = @"";
    appIdEntry.text = @"";
    clientIdEntry.text = @"";
    userIdentifierEntry.text = @"";
    nameEntry.text = @"";
    emailEntry.text = @"";
    externalIdEntry.text = @"";
    
    [[ZDKSdkStorage instance] clearUserData];
    [[ZDKSdkStorage instance].settingsStorage deleteStoredData];
}


- (void) doneButtonPressed
{

    NSMutableDictionary *valuesToSave = [[NSMutableDictionary alloc] initWithCapacity:4];
    [valuesToSave setObject:urlEntry.text forKey:@"url"];
    [valuesToSave setObject:appIdEntry.text forKey:@"appId"];
    [valuesToSave setObject:clientIdEntry.text forKey:@"clientId"];
    [valuesToSave setObject:userIdentifierEntry.text forKey:@"userId"];
    [valuesToSave setObject:nameEntry.text forKey:@"name"];
    [valuesToSave setObject:emailEntry.text forKey:@"email"];
    [valuesToSave setObject:externalIdEntry.text forKey:@"externalId"];
    [valuesToSave setObject:@(authenticationType.selectedSegmentIndex) forKey:@"authType"];


    [self saveSettings:valuesToSave];

    if (delegate) {

        if (authenticationType.selectedSegmentIndex == ZDSDKAuthJwt) {

            [ZDKConfig instance].userIdentity = [[ZDKJwtIdentity alloc] initWithJwtUserIdentifier:userIdentifierEntry.text];

        } else {

            ZDKAnonymousIdentity *identity = [ZDKAnonymousIdentity new];

            identity.name = nameEntry.text;
            identity.email = emailEntry.text;
            identity.externalId = externalIdEntry.text;

            [ZDKConfig instance].userIdentity = identity;

        }

        [delegate configuration:urlEntry.text withAppId:appIdEntry.text andClientId:clientIdEntry.text];
    }

    [self dismissViewControllerAnimated:YES completion:nil];
}


- (void) saveSettings:(NSDictionary *)config
{
    if (config) {

        [[NSUserDefaults standardUserDefaults] setObject:[NSKeyedArchiver archivedDataWithRootObject:config]
                                                  forKey:ZDSDKSampleAppDefaultsKey];
        [[NSUserDefaults standardUserDefaults] synchronize];

    }
}


#pragma mark - Authentication switch


- (void) authTypeChanged:(UISegmentedControl *)segment
{

    if (segment.selectedSegmentIndex == ZDSDKAuthJwt) {

        userIdentifierEntry.hidden = NO;
        userIdentifierEntry.tag = 4;
        nameEntry.hidden = YES;
        nameEntry.tag = INT16_MAX;
        emailEntry.hidden = YES;
        externalIdEntry.hidden = YES;

    } else {

        nameEntry.hidden = NO;
        nameEntry.tag = 4;
        emailEntry.hidden = NO;
        externalIdEntry.hidden = NO;
        userIdentifierEntry.hidden = YES;
        userIdentifierEntry.tag = INT16_MAX;
    }
}


#pragma mark - Text Field Delegate


- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    
    NSInteger nextTag = textField.tag + 1;
    // Try to find next responder
    UIResponder* nextResponder = [textField.superview viewWithTag:nextTag];
    if (nextResponder) {
        // Found next responder, so set it.
        [nextResponder becomeFirstResponder];
    }
    
    if (textField.returnKeyType == UIReturnKeyDone) {
        [textField resignFirstResponder];
        [self doneButtonPressed];
    }
    
    return NO;
    
}


#pragma mark - Util


- (void)keyboardWillBeShown:(NSNotification*)aNotification
{
    CGFloat margin = ZDSDKPadding + authenticationType.frame.size.height +
                     ZDSDKPadding + nameEntry.frame.size.height +
                     ZDSDKPadding + emailEntry.frame.size.height +
                     ZDSDKPadding + externalIdEntry.frame.size.height + ZDSDKPadding;
    
    [self.scrollView setContentSize:CGSizeMake(self.view.frame.size.width, self.view.frame.size.height + margin)];
}

- (void)keyboardWillBeHidden:(NSNotification*)aNotification
{
    [self.scrollView setContentSize:CGSizeMake(self.view.frame.size.width, self.view.frame.size.height)];
}


- (UITextField *) buildTextFieldWithPlaceholder:(NSString *)placeholder
                                   keyboardType:(UIKeyboardType)keyboard
                                      returnKey:(UIReturnKeyType)key
                                         andTag:(NSInteger)tag
{

    UITextField *textField = [[UITextField alloc] initWithFrame:CGRectZero];
    textField.keyboardType = keyboard;
    textField.font = [UIFont systemFontOfSize:14];
    textField.returnKeyType = key;
    textField.tag = tag;
    textField.placeholder = placeholder;
    textField.delegate = self;
    textField.autocapitalizationType = UITextAutocapitalizationTypeNone;
    textField.autocorrectionType = UITextAutocorrectionTypeNo;
    textField.translatesAutoresizingMaskIntoConstraints = NO;


    [self applyBackgroundStyling:textField];
    [self addPaddingToTextField:textField];

    return textField;
}


- (UILabel *) buildLableWithText:(NSString *)text
{
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectZero];
    label.lineBreakMode = NSLineBreakByWordWrapping;
    label.font = [UIFont systemFontOfSize:14];
    label.numberOfLines = 0;
    label.text = text;

    return label;
}


- (void) applyBackgroundStyling: (UIView *) view
{
    view.backgroundColor = [UIColor whiteColor];
    view.layer.borderColor = [UIColor colorWithWhite:0.8470f alpha:1.0f].CGColor;
    view.layer.borderWidth = 1.0f;
    view.layer.cornerRadius = 4.0f;
}


- (void) addPaddingToTextField: (UITextField *) textField
{
    UIView *paddingView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 5, 20)];

    textField.leftView = paddingView;
    textField.leftViewMode = UITextFieldViewModeAlways;
}



@end
