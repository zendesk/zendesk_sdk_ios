//
//  ZDCoreSDKSampleAppConfigurationViewController.m
//  CoreSDKSample
//
//  Created by Zendesk on 11/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import "ZDCoreSDKSampleAppConfigurationViewController.h"

static NSString * const ZDSDKSampleAppDefaultsKey = @"ZDSDKSampleAppDefaultsKey";
static CGFloat const ZD_CORE_SAMPLE_CONFIRGUATION_LABEL_EXTRA_HEIGHT = 40.0f;


@interface ZDCoreSDKSampleAppConfigurationViewController ()

@property (nonatomic, strong) UILabel *urlDescriptionLabel;
@property (nonatomic, strong) UITextField *urlEntryTextView;
@property (nonatomic, strong) UITextField *appIdEntryTextView;
@property (nonatomic, strong) UITextField *clientIdEntryTextView;
@property (nonatomic, strong) UITextField *userTokenEntryTextView;
@property (nonatomic, strong) UILabel *optionsConversationsConfigurationLabel;
@property (nonatomic, strong) UIView *paddingView;

- (void) saveSettings:(NSDictionary *) settings;

@end



@implementation ZDCoreSDKSampleAppConfigurationViewController

@synthesize delegate;


- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"SDK Sample App Setup";
    
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
    
    _urlDescriptionLabel = [self buildLableWithText:@"Enter your Zendesk URL like \'mysubdomain\' or an ip address like: \'http://192.168.1.10:80\'"];

    [self.contentView addSubview:_urlDescriptionLabel];
    
    _urlEntryTextView = [self buildTextFieldWithPlaceholder:@"URL to Zendesk"
                                               keyboardType:UIKeyboardTypeURL
                                                  returnKey:UIReturnKeyNext
                                                     andTag:1];

    [self applyBackgroundStyling:_urlEntryTextView];
    [self addPaddingToTextField:_urlEntryTextView];
    
    [self.contentView addSubview:_urlEntryTextView];
    
    _appIdEntryTextView = [self buildTextFieldWithPlaceholder:@"Application ID"
                                                 keyboardType:UIKeyboardTypeAlphabet
                                                    returnKey:UIReturnKeyNext
                                                       andTag:2];
    
    
    [self applyBackgroundStyling:_appIdEntryTextView];
    [self addPaddingToTextField:_appIdEntryTextView];

    [self.contentView addSubview:_appIdEntryTextView];
    
    _optionsConversationsConfigurationLabel = [self buildLableWithText:@"The following fields are only required in order to configure the conversations component"];

    [self.contentView addSubview:_optionsConversationsConfigurationLabel];
    
    
    _clientIdEntryTextView = [self buildTextFieldWithPlaceholder:@"Client ID (optional)"
                                                    keyboardType:UIKeyboardTypeAlphabet
                                                       returnKey:UIReturnKeyNext
                                                          andTag:3];


    [self applyBackgroundStyling:_clientIdEntryTextView];
    [self addPaddingToTextField:_clientIdEntryTextView];
    
    [self.contentView addSubview:_clientIdEntryTextView];
    
    _userTokenEntryTextView = [self buildTextFieldWithPlaceholder:@"User ID (optional)"
                                                     keyboardType:UIKeyboardTypeAlphabet
                                                        returnKey:UIReturnKeyDone
                                                           andTag:4];


    [self applyBackgroundStyling:_userTokenEntryTextView];
    [self addPaddingToTextField:_userTokenEntryTextView];

    [self.contentView addSubview:_userTokenEntryTextView];


    NSData *storedConfig = [[NSUserDefaults standardUserDefaults] objectForKey:ZDSDKSampleAppDefaultsKey];
    
    if (storedConfig) {
        
        NSDictionary *config = (NSDictionary *)[NSKeyedUnarchiver unarchiveObjectWithData:storedConfig];
        if (config) {
        
            _urlEntryTextView.text = (NSString *)config[@"url"];
            _appIdEntryTextView.text = (NSString *)config[@"appId"];
            _clientIdEntryTextView.text = (NSString *)config[@"clientId"];
            _userTokenEntryTextView.text = (NSString *)config[@"userToken"];
        }
    } else {
        [_urlEntryTextView becomeFirstResponder];
    }
}


- (void) viewWillLayoutSubviews
{
    [super viewWillLayoutSubviews];
    
    CGSize maximumLabelSize = CGSizeMake(self.view.frame.size.width -40.0f, CGFLOAT_MAX);
    
    CGSize urlDescriptionExpectedLabelSize = [_urlDescriptionLabel sizeThatFits:maximumLabelSize];
    
    _urlDescriptionLabel.frame = CGRectMake(20.0f,
                                            0,
                                            self.view.frame.size.width -40.0f,
                                            urlDescriptionExpectedLabelSize.height + ZD_CORE_SAMPLE_CONFIRGUATION_LABEL_EXTRA_HEIGHT);

    _urlEntryTextView.frame = CGRectMake(20.0f, _urlDescriptionLabel.frame.origin.y + urlDescriptionExpectedLabelSize.height + 20.0f,
                                              self.view.frame.size.width - 40.0f, 30.0f);
    
    
    _appIdEntryTextView.frame = CGRectMake(20.0f, _urlEntryTextView.frame.origin.y + 40.0f,
                                                      self.view.frame.size.width - 40.0f, 30.0f);
    
    CGSize optionalLabelExpectedLabelSize = [_optionsConversationsConfigurationLabel sizeThatFits:maximumLabelSize];
    
    _optionsConversationsConfigurationLabel.frame = CGRectMake(20.0f,
                                            _appIdEntryTextView.frame.origin.y + 20.0f,
                                            self.view.frame.size.width -40.0f,
                                            optionalLabelExpectedLabelSize.height + ZD_CORE_SAMPLE_CONFIRGUATION_LABEL_EXTRA_HEIGHT);
    
    
    _clientIdEntryTextView.frame = CGRectMake(20.0f, _optionsConversationsConfigurationLabel.frame.origin.y + optionalLabelExpectedLabelSize.height + 20.0f,
                                                 self.view.frame.size.width - 40.0f, 30.0f);
    
    _userTokenEntryTextView.frame = CGRectMake(20.0f, _clientIdEntryTextView.frame.origin.y + 40.0f,
                                         self.view.frame.size.width - 40.0f, 30.0f);
    
}


#pragma mark - Button Actions 


- (void) clearButtonPressed
{
    
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:ZDSDKSampleAppDefaultsKey];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    _urlEntryTextView.text = @"";
    _appIdEntryTextView.text = @"";
    _clientIdEntryTextView.text = @"";
    _userTokenEntryTextView.text = @"";
}


- (void) doneButtonPressed
{

    NSMutableDictionary *valuesToSave = [[NSMutableDictionary alloc] initWithCapacity:4];
    [valuesToSave setObject:_urlEntryTextView.text forKey:@"url"];
    [valuesToSave setObject:_appIdEntryTextView.text forKey:@"appId"];
    [valuesToSave setObject:_clientIdEntryTextView.text forKey:@"clientId"];
    [valuesToSave setObject:_userTokenEntryTextView.text forKey:@"userToken"];

    [self saveSettings:valuesToSave];

    if (delegate) {
        [delegate configuration:_urlEntryTextView.text
                      withAppId:_appIdEntryTextView.text
                   withClientId:_clientIdEntryTextView.text
                     withUserId:_userTokenEntryTextView.text];
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
    
    if (textField == _userTokenEntryTextView) {
        [textField resignFirstResponder];
        [self doneButtonPressed];
    }
    
    return NO;
    
}



#pragma mark - Util


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
