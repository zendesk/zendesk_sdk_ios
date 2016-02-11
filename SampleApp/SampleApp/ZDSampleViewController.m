//
//  ZDSampleViewController.m
//  SampleApp
//
//  Created by Zendesk on 25/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDSampleViewController.h"
#import "ZDRateMyAppDemoViewController.h"
#import <ZendeskSDK/ZendeskSDK.h>
#import "ZDFlatArticlesTableViewController.h"

static CGFloat const PADDING = 15.f;

@interface ZDSampleViewController ()

@property (nonatomic, strong) UIScrollView* scrollView;

@property (nonatomic, strong) UIView* scrollViewContent;

@property (nonatomic, assign) BOOL configPresented;
@property (nonatomic, assign) CGRect originalContentFrame;
@property (nonatomic, assign) CGFloat contentHeight;

@end


@implementation ZDSampleViewController


@synthesize rmaButton, requestCreationButton, requestListButton, helpCenterButton, helpCenterWithFlatArticlesButton, helpCenterLabelsInput, helpCenterCategoryIdInput, helpCenterSectionIdInput;
@synthesize registerPush, unregisterPush;
@synthesize userTagsInput, addTagsButton, removeTagsButton;
@synthesize scrollView, scrollViewContent;

- (void) viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"SDK Sample";
    
    scrollView = [[UIScrollView alloc] initWithFrame:self.view.frame];
    scrollViewContent = [[UIView alloc] initWithFrame:self.view.frame];
    
    
    [self.contentView addSubview:scrollView];
    [self.scrollView addSubview:scrollViewContent];
    self.scrollView.translatesAutoresizingMaskIntoConstraints = NO;
    
    rmaButton = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Show Rate My App"];
    rmaButton.accessibilityIdentifier = @"rmaButton";
    rmaButton.backgroundColor = [UIColor whiteColor];
    [rmaButton addTarget:self action:@selector(rateMyApp) forControlEvents:UIControlEventTouchUpInside];
    [self.scrollViewContent addSubview:rmaButton];

    requestCreationButton = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Contact Zendesk"];
    requestCreationButton.accessibilityIdentifier = @"contactZendeskButton";
    requestCreationButton.backgroundColor = [UIColor whiteColor];
    [requestCreationButton addTarget:self action:@selector(createRequest) forControlEvents:UIControlEventTouchUpInside];
    [self.scrollViewContent addSubview:requestCreationButton];

    requestListButton = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Ticket List"];
    requestListButton.accessibilityIdentifier = @"ticketListButton";
    requestListButton.backgroundColor = [UIColor whiteColor];
    [requestListButton addTarget:self action:@selector(requestListView) forControlEvents:UIControlEventTouchUpInside];
    [self.scrollViewContent addSubview:requestListButton];


    helpCenterLabelsInput = [ZDSampleViewController buildTextFieldWithFrame:CGRectZero andPlaceholder:@"label1,label2,label3 (optional)"];
    helpCenterLabelsInput.accessibilityIdentifier = @"hcLabelsField";
    helpCenterLabelsInput.backgroundColor = [UIColor whiteColor];
    helpCenterLabelsInput.delegate = self;
    //helpCenterButton pulls these out
    [self.scrollViewContent addSubview:helpCenterLabelsInput];
    
    helpCenterCategoryIdInput = [ZDSampleViewController buildTextFieldWithFrame:CGRectZero andPlaceholder:@"Category ID"];
    helpCenterCategoryIdInput.accessibilityIdentifier = @"hcCategoryIdField";
    helpCenterCategoryIdInput.backgroundColor = [UIColor whiteColor];
    helpCenterCategoryIdInput.delegate = self;
    [self.scrollViewContent addSubview:helpCenterCategoryIdInput];
    
    helpCenterSectionIdInput = [ZDSampleViewController buildTextFieldWithFrame:CGRectZero andPlaceholder:@"Section ID"];
    helpCenterSectionIdInput.accessibilityIdentifier = @"hcSectionIdField";
    helpCenterSectionIdInput.backgroundColor = [UIColor whiteColor];
    helpCenterSectionIdInput.delegate = self;
    [self.scrollViewContent addSubview:helpCenterSectionIdInput];
    
    
    helpCenterButton = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Support"];
    helpCenterButton.accessibilityIdentifier = @"supportButton";
    helpCenterButton.backgroundColor = [UIColor whiteColor];
    [helpCenterButton addTarget:self action:@selector(support) forControlEvents:UIControlEventTouchUpInside];
    [self.scrollViewContent addSubview:helpCenterButton];
    
    helpCenterWithFlatArticlesButton = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Help Center Articles"];
    helpCenterWithFlatArticlesButton.accessibilityIdentifier = @"supportWithFlatArticlesListButton";
    helpCenterWithFlatArticlesButton.backgroundColor = [UIColor whiteColor];
    [helpCenterWithFlatArticlesButton addTarget:self action:@selector(supportWithFlatArticlesList) forControlEvents:UIControlEventTouchUpInside];
    [self.scrollViewContent addSubview:helpCenterWithFlatArticlesButton];
    

    registerPush = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Register Push"];
    registerPush.accessibilityIdentifier = @"registerButton";
    registerPush.backgroundColor = [UIColor whiteColor];
    [registerPush addTarget:self action:@selector(registerForPush) forControlEvents:UIControlEventTouchUpInside];
    [self.scrollViewContent addSubview:registerPush];
    
    unregisterPush = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Unregister Push"];
    unregisterPush.accessibilityIdentifier = @"unregisterButton";
    unregisterPush.backgroundColor = [UIColor whiteColor];
    [unregisterPush addTarget:self action:@selector(unregisterForPush) forControlEvents:UIControlEventTouchUpInside];
    [self.scrollViewContent addSubview:unregisterPush];
    
    userTagsInput = [ZDSampleViewController buildTextFieldWithFrame:CGRectZero andPlaceholder:@"User Tags"];
    userTagsInput.accessibilityIdentifier = @"addTagsInput";
    userTagsInput.backgroundColor = [UIColor whiteColor];
    userTagsInput.delegate = self;
    [self.scrollViewContent addSubview:userTagsInput];
    
    addTagsButton = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Add Tags"];
    addTagsButton.accessibilityIdentifier = @"addTagsButton";
    addTagsButton.backgroundColor = [UIColor whiteColor];
    [addTagsButton addTarget:self action:@selector(addTags) forControlEvents:UIControlEventTouchUpInside];
    [self.scrollViewContent addSubview:addTagsButton];
    
    removeTagsButton = [ZDSampleViewController buildButtonWithFrame:CGRectZero andTitle:@"Remove Tags"];
    removeTagsButton.accessibilityIdentifier = @"removeTagsButton";
    removeTagsButton.backgroundColor = [UIColor whiteColor];
    [removeTagsButton addTarget:self action:@selector(removeTags) forControlEvents:UIControlEventTouchUpInside];
    [self.scrollViewContent addSubview:removeTagsButton];
    
    
    [self setupConstraints];

    super.layoutGuide = ZDKLayoutRespectTop;
    
}

- (void) viewDidAppear:(BOOL)animated
{
    if ( ! _configPresented ) {
        ZDSampleAppConfigurationViewController *configurationVC = [[ZDSampleAppConfigurationViewController alloc] initWithNibName:nil bundle:nil];
        configurationVC.delegate = self;
        
        UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:configurationVC];
        
        [self presentViewController:navController animated:NO completion:^{
            _configPresented = YES;
        }];
        
    }
    
    _originalContentFrame = CGRectMake(self.view.frame.origin.x,
                                    self.view.frame.origin.y,
                                    self.view.frame.size.width,
                                    _contentHeight + [self topViewOffset]);
    
    [self.scrollView setContentSize:_originalContentFrame.size];
    
    [self registerForKeyboardNotifications];
}

- (void) viewDidDisappear:(BOOL)animated
{
    [self unregisterForKeyboardNotifications];
}


- (void) setupConstraints
{
    NSDictionary *metrics = @{@"padding":@(20), @"height":@(30)};

    NSDictionary *views = NSDictionaryOfVariableBindings(rmaButton,
                                                         requestCreationButton,
                                                         requestListButton,
                                                         helpCenterLabelsInput,
                                                         helpCenterCategoryIdInput,
                                                         helpCenterSectionIdInput,
                                                         helpCenterButton,
                                                         helpCenterWithFlatArticlesButton,
                                                         registerPush,
                                                         unregisterPush,
                                                         userTagsInput,
                                                         addTagsButton,
                                                         removeTagsButton,
                                                         scrollViewContent,
                                                         scrollView);
    

    
    [self.contentView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|[scrollView]|" options:0 metrics:0 views:views]];
    [self.contentView addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[scrollView]|" options:0 metrics:0 views:views]];


    [self.scrollViewContent addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-padding-[rmaButton]-padding-|"
                                                                             options:NSLayoutFormatAlignmentMask
                                                                             metrics:metrics
                                                                               views:views]];
    


    NSArray *contentHeight = [NSLayoutConstraint constraintsWithVisualFormat:@"V:|-[rmaButton(height)]-padding-[requestCreationButton(height)]-padding-[requestListButton(height)]-padding-[helpCenterLabelsInput(height)]-padding-[helpCenterCategoryIdInput(height)]-padding-[helpCenterSectionIdInput(height)]-padding-[helpCenterButton(height)]-padding-[helpCenterWithFlatArticlesButton(height)]-padding-[registerPush(height)]-padding-[unregisterPush(height)]-padding-[userTagsInput(height)]-padding-[addTagsButton(height)]-padding-[removeTagsButton(height)]"

                                                                               options:NSLayoutFormatAlignAllLeft | NSLayoutFormatAlignAllRight
                                                                               metrics:metrics
                                                                                 views:views];
    
    
    for (NSLayoutConstraint *constraint in contentHeight)
    {
        _contentHeight += constraint.constant;
    }
    
    [self.scrollViewContent addConstraints:contentHeight];
    

}

- (void) layoutContent
{
    [super layoutContent];
    self.scrollViewContent.frame = CGRectMake(self.contentView.frame.origin.x,
                                              self.contentView.frame.origin.y - [self topViewOffset],
                                              self.contentView.frame.size.width, _contentHeight + PADDING);
}


#pragma mark - SDK


- (void) requestListView
{
    if([ZDKUIUtil isPad]) {

        self.navigationController.modalPresentationStyle = UIModalPresentationFormSheet;
        [ZDKRequests presentRequestListWithNavController:self.navigationController];

    } else {
        
        [ZDKRequests showRequestListWithNavController:self.navigationController];
    }
}


- (void) support
{
    
    if (helpCenterLabelsInput.hasText) {

        NSString *labelString = helpCenterLabelsInput.text;
        NSArray *labels = [labelString componentsSeparatedByString:@","];


        if([ZDKUIUtil isPad]) {

            self.navigationController.modalPresentationStyle = UIModalPresentationFormSheet;
            [ZDKHelpCenter presentHelpCenterWithNavController:self.navigationController filterByArticleLabels:labels];

        } else {

            [ZDKHelpCenter showHelpCenterWithNavController:self.navigationController filterByArticleLabels:labels];
        }

    } else if (helpCenterCategoryIdInput.hasText) {
        NSString *categoryIdString = helpCenterCategoryIdInput.text;
        
        if ([ZDKUIUtil isPad]) {
            
            self.navigationController.modalPresentationStyle = UIModalPresentationFormSheet;
            // categoryName will default to "Supoort" if set to nil
            [ZDKHelpCenter presentHelpCenterWithNavController:self.navigationController filterByCategoryId:categoryIdString categoryName:@"Example name" layoutGuide:ZDKLayoutRespectAll];
            
        } else {
            
            [ZDKHelpCenter showHelpCenterWithNavController:self.navigationController filterByCategoryId:categoryIdString categoryName:@"Example name" layoutGuide:ZDKLayoutRespectAll];
            
        }
        
    } else if (helpCenterSectionIdInput.hasText) {
        NSString *sectionIdString = helpCenterSectionIdInput.text;
        
        if ([ZDKUIUtil isPad]) {
            
            self.navigationController.modalPresentationStyle = UIModalPresentationFormSheet;
            [ZDKHelpCenter presentHelpCenterWithNavController:self.navigationController filterBySectionId:sectionIdString sectionName:@"Example name" layoutGuide:ZDKLayoutRespectAll];
        } else {
            
            [ZDKHelpCenter showHelpCenterWithNavController:self.navigationController filterBySectionId:sectionIdString sectionName:@"Example name" layoutGuide:ZDKLayoutRespectAll];
        }
        
    } else {

        if([ZDKUIUtil isPad]) {

            self.navigationController.modalPresentationStyle = UIModalPresentationFormSheet;
            [ZDKHelpCenter presentHelpCenterWithNavController:self.navigationController];

        } else {

            [ZDKHelpCenter showHelpCenterWithNavController:self.navigationController layoutGuide:ZDKLayoutRespectAll];
        }
    }
}

- (void) supportWithFlatArticlesList
{
    
    ZDKHelpCenterProvider *provider = [ZDKHelpCenterProvider new];
    
    [provider getFlatArticlesWithCallback:^(NSArray *items, NSError *error) {
        ZDFlatArticlesTableViewController *flatArticlesViewController = [[ZDFlatArticlesTableViewController alloc]init];
        flatArticlesViewController.items = items;
        [flatArticlesViewController processFlatArticles];
        
        if([ZDKUIUtil isPad]) {
            UINavigationController* navController = [[UINavigationController alloc] initWithRootViewController:flatArticlesViewController];
            navController.modalTransitionStyle = self.navigationController.modalTransitionStyle;
            navController.modalPresentationStyle = UIModalPresentationFormSheet;
            flatArticlesViewController.modalPresentationStyle = UIModalPresentationFormSheet;
            [self.navigationController presentViewController:navController animated:YES completion:nil];
        } else {
            
            [self.navigationController pushViewController:flatArticlesViewController animated:YES];
        }
    }];
}

- (void) rateMyApp
{
    ZDRateMyAppDemoViewController *vc = [[ZDRateMyAppDemoViewController alloc] initWithNibName:nil bundle:nil];
    [self.navigationController pushViewController:vc animated:YES];
}


#pragma mark request creation


- (void) createRequest
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Show the request creation screen
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if([ZDKUIUtil isPad]) {
        
        self.navigationController.modalPresentationStyle = UIModalPresentationFormSheet;
    }

    [ZDKRequests showRequestCreationWithNavController:self.navigationController];
}

#pragma mark Push notifications

- (void) registerForPush
{
    
    NSString *identifier = [self getDeviceId];

    [[ZDKConfig instance] enablePushWithDeviceID:identifier callback:^(ZDKPushRegistrationResponse *registrationResponse, NSError *error) {

        NSString *title;

        if (error) {
            
            title = @"Registration Failed";
            [ZDKLogger e:@"Couldn't register device: %@. Error: %@", identifier, error];
            
        } else if (registrationResponse) {
            
            title = @"Registration Successful";
            [ZDKLogger d:@"Successfully registered device: %@", identifier];
        }

        UIAlertView * alert = [[UIAlertView alloc] initWithTitle:title message:nil delegate:nil cancelButtonTitle:@"OK" otherButtonTitles: nil];
        [alert show];
    }];
}

- (void) unregisterForPush
{
    NSString *identifier = [self getDeviceId];
    
    [[ZDKConfig instance] disablePush:identifier callback:^(NSNumber *responseCode, NSError *error) {

        NSString *title;

        if (error) {
            
            title = @"Failed to Unregister";
            [ZDKLogger e:@"Couldn't unregister device: %@. Error: %@", identifier, error];
            
        } else if (responseCode) {
            
            title = @"Unregistered";
            [ZDKLogger d:@"Successfully unregistered device: %@", identifier];
        }

        UIAlertView * alert = [[UIAlertView alloc] initWithTitle:title message:nil delegate:nil cancelButtonTitle:@"OK" otherButtonTitles: nil];
        [alert show];
    }];
    
}

- (NSString*) getDeviceId
{
    NSString *result = [[NSUserDefaults standardUserDefaults] objectForKey:APPLE_PUSH_UUID];
    
    return result;
}

#pragma mark - User tags

- (void) addTags
{
    NSString *tagsString = userTagsInput.text;
    //Not checking the input as an empty argument acts like a get request.
    //No nil check as sending up no tags is effectivly a GET tags request.
    NSArray *tags = [tagsString componentsSeparatedByString:@","];

    [[ZDKUserProvider new] addTags:tags callback:^(NSArray *userTags, NSError *error) {
        NSString *tagsResponse = [[userTags valueForKey:@"description"] componentsJoinedByString:@", "];
        [self showAlertWithTitle:@"User Tags" andText:tagsResponse];
    }];

}

- (void) removeTags
{
    NSString *tagsString = userTagsInput.text;
    //Nil check as deleteTags without any tags does nothing.
    if ( ! [tagsString isEqualToString:@""] )
    {
        NSArray *tags = [tagsString componentsSeparatedByString:@","];

        [[ZDKUserProvider new] deleteTags:tags callback:^(NSArray *userTags, NSError *error) {
            NSString *tagsResponse = [[userTags valueForKey:@"description"] componentsJoinedByString:@", "];
            [self showAlertWithTitle:@"User Tags" andText:tagsResponse];
        }];
        
    }
}

#pragma mark - control creation


+ (UIControl *) buildControl:(UIControl *) control
{
    control.layer.borderColor = [UIColor colorWithWhite:0.8470f alpha:1.0f].CGColor;
    control.translatesAutoresizingMaskIntoConstraints = NO;
    control.layer.borderWidth = 1.0f;
    control.layer.cornerRadius = 4.0f;
    return control;
}


+ (UITextField *) buildTextFieldWithFrame:(CGRect)frame andPlaceholder:(NSString *)placeholder
{
    UITextField * textField = [[UITextField alloc] initWithFrame:frame];
    textField = (UITextField *)[self buildControl:textField];
    textField.textAlignment = NSTextAlignmentCenter;
    textField.placeholder = placeholder;

    return textField;
}


+ (UIButton *) buildButtonWithFrame:(CGRect)frame andTitle:(NSString*)title
{
    UIButton *button = [[UIButton alloc] initWithFrame:frame];
    button = (UIButton *)[self buildControl:button];
    
    button.titleLabel.font = [UIFont systemFontOfSize:14];
    [button setTitleColor:[UIColor colorWithWhite:0.2627f alpha:1.0f] forState:UIControlStateNormal];
    [button setTitleColor:[UIColor colorWithWhite:0.2627f alpha:0.3f] forState:UIControlStateHighlighted];
    [button setTitleColor:[UIColor colorWithWhite:0.2627f alpha:0.3f] forState:UIControlStateDisabled];
    [button setTitle:title forState:UIControlStateNormal];
    [button setTitle:title forState:UIControlStateHighlighted];
    button.titleLabel.textAlignment = NSTextAlignmentCenter;
    
    return button;
}


- (void)configuration:(NSString *)url withAppId:(NSString *)appId andClientId:(NSString *)clientId
{
    NSLog(@"configuration made, url: %@, appId: %@ and clientId: %@",url,appId,clientId);
    [[ZDKConfig instance] initializeWithAppId:appId zendeskUrl:url ClientId:clientId onSuccess:^() {
        NSLog(@"Config found, SDK is ready");
    } onError:^(NSError *error) {
        NSLog(@"Config could not be fetched.");
    }];    
}


#pragma mark - Util

- (void) showAlertWithTitle:(NSString*)title andText:(NSString*) text
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title
                                                    message:text
                                                   delegate:nil
                                          cancelButtonTitle:@"OK"
                                          otherButtonTitles:nil];
    [alert show];
}


- (void)keyboardDidShow:(NSNotification *)aNotification
{
    [super keyboardDidShow:aNotification];
    self.scrollView.frame = CGRectMake(self.view.frame.origin.x,
                                       self.view.frame.origin.y,
                                       self.view.frame.size.width,
                                       self.view.frame.size.height - _keyboardHeight - PADDING);
    
}

- (void)keyboardDidHide:(NSNotification*)aNotification
{
    [super keyboardDidHide:aNotification];
    self.scrollView.frame = CGRectMake(self.view.frame.origin.x,
                                       self.view.frame.origin.y,
                                       self.view.frame.size.width,
                                       self.view.frame.size.height - PADDING);
}

- (void) registerForKeyboard
{
 
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardDidShow:)
                                                 name:UIKeyboardDidShowNotification
                                               object:nil];
    
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardDidHide:)
                                                 name:UIKeyboardDidHideNotification
                                               object:nil];
    
}

- (void) unregisterForKeyboardNotifications
{
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardDidShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIKeyboardDidHideNotification object:nil];
}


- (void) dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

#pragma mark - textfield delegate 

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return YES;
}


@end
