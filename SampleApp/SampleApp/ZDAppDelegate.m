//
//  ZDAppDelegate.m
//  SampleApp
//
//  Created by Zendesk on 23/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "NSData+ZDKSampleApp.h"
#import "ZDAppDelegate.h"
#import "ZDSampleViewController.h"
#import <ZendeskSDK/ZendeskSDK.h>


@implementation ZDAppDelegate

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error
{
    [ZDKLogger e:@"Device failed to register with error: %@\n%@", error, error.localizedDescription];
}


- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    NSString *identifier = [deviceToken deviceIdentifier];

    [ZDKLogger d:@"Device registered for remote notifications with identifier: %@", identifier ];

    [[NSUserDefaults standardUserDefaults] setObject:identifier forKey:APPLE_PUSH_UUID];
}


- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler
{
    NSData *storedConfig = [[NSUserDefaults standardUserDefaults] objectForKey:@"ZDSDKSampleAppDefaultsKey"];

    if (storedConfig) {

        NSDictionary *config = (NSDictionary *)[NSKeyedUnarchiver unarchiveObjectWithData:storedConfig];

        if (config) {

            [ZDKPushUtil handlePush:userInfo
                     forApplication:application
                  presentationStyle:UIModalPresentationFormSheet
                        layoutGuide:ZDKLayoutRespectTop
                          withAppId:config[@"appId"]
                         zendeskUrl:config[@"url"]
                           clientId:config[@"clientId"]
             fetchCompletionHandler:completionHandler];
        }
    }

}


- (BOOL) application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
{
    [ZDKLogger enable:YES];

#if !TARGET_IPHONE_SIMULATOR


    // Register the app for remote notifications
    if ([UIApplication instancesRespondToSelector:@selector(registerForRemoteNotifications)]) {

        UIUserNotificationType types = UIUserNotificationTypeAlert | UIUserNotificationTypeBadge | UIUserNotificationTypeSound;
        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:types categories:nil];
        [application registerUserNotificationSettings:settings];
        [application registerForRemoteNotifications];

    } else if ([UIApplication instancesRespondToSelector:@selector(registerForRemoteNotificationTypes:)]) {

        UIRemoteNotificationType types = UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound;
        [application registerForRemoteNotificationTypes:types];
    }

#endif


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // OPTIONAL - you can choose to set tags or additional info at any stage
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    [ZDKRequests configure:^(ZDKAccount *account, ZDKRequestCreationConfig *requestCreationConfig) {

        // specify any additional tags desired
        requestCreationConfig.tags = [NSArray arrayWithObjects:@"tag_one", @"tag_two", nil];

        // add some custom content to the description
        NSString *additionalText = @"Some sample extra content.";
        NSString *txt = [NSString stringWithFormat:@"%@%@", [requestCreationConfig contentSeperator], additionalText];

        requestCreationConfig.additionalRequestInfo = txt;
        
        //Set the subject of requests created by the user.
        requestCreationConfig.subject = @"App Ticket";
    }];
    
    
    [ZDKRMA configure:^(ZDKAccount *account, ZDKRMAConfigObject *config) {  
        
        //account.email = @"example@example.com";

        
        // configgure additional info
        NSString *versionString = [NSString stringWithFormat:@"%@ (%@)",
                                   [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"],
                                   [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]];
        
        NSString *appVersion = [NSString stringWithFormat:@"App version: %@", versionString];
        
        config.additionalRequestInfo = [NSString stringWithFormat:@"Additional info here.\n%@", appVersion];
    }];



    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Sample app boilerplate
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

    self.window.backgroundColor = [UIColor colorWithWhite:0.94f alpha:1.0f];
    
    // top view controller
    ZDSampleViewController *vc = [[ZDSampleViewController alloc] initWithNibName:nil bundle:nil];
    
    // nav controller
    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:vc];
    navController.modalTransitionStyle = UIModalTransitionStyleCoverVertical;
    
    // assign nav controller as root
    self.window.rootViewController = navController;
    
    // make key window
    [self.window makeKeyAndVisible];
    
    //Add auth to image requests in Help Center.
    [NSURLProtocol registerClass:[ZDKAuthenticationURLProtocol class]];
    
    if (SYSTEM_VERSION_GREATER_THAN_SEVEN) {
        
        // status bar
        [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
        
        // nav bar
        NSDictionary *navbarAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
                                          [UIColor whiteColor] ,NSForegroundColorAttributeName, nil];
        [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
        [[UINavigationBar appearance] setBarTintColor:[UIColor colorWithRed:0.4705f green:0.6392f blue:0.0f alpha:1.0f]];
        [[UINavigationBar appearance] setTitleTextAttributes:navbarAttributes];
    }
    
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // OPTIONAL - Customize appearance
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // [self setDarkNeoStyle];
    
    
    return YES;
}


- (void)applicationWillTerminate:(UIApplication *)application
{
    [NSURLProtocol unregisterClass:[ZDKAuthenticationURLProtocol class]];
}


- (void) setDefaultStyle {
    
    if (SYSTEM_VERSION_GREATER_THAN_SEVEN) {
        
        // status bar
        [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
        
        // nav bar
        NSDictionary *navbarAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
                                          [UIColor whiteColor] ,NSForegroundColorAttributeName, nil];
        [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
        [[UINavigationBar appearance] setBarTintColor:[UIColor colorWithRed:0.4705f green:0.6392f blue:0.0f alpha:1.0f]];
        [[UINavigationBar appearance] setTitleTextAttributes:navbarAttributes];
    }
  
    ZDKTheme *theme = [ZDKTheme baseTheme];
    
    theme.primaryTextColor = [UIColor colorWithWhite:0.2627f alpha:1.0f];
    theme.primaryBackgroundColor = [UIColor colorWithWhite:1.0f alpha:1.0f];
    theme.secondaryBackgroundColor = [UIColor colorWithWhite:0.976f alpha:1.0f];
    theme.emptyBackgroundColor = [UIColor colorWithWhite:0.945f alpha:1.0f];
    theme.metaTextColor = [UIColor colorWithWhite:0.721f alpha:1.0f];
    theme.separatorColor = [UIColor colorWithWhite:0.9f alpha:1.0f];
    theme.inputFieldBackgroundColor = [UIColor colorWithWhite:0.945f alpha:1.0f];
    theme.inputFieldTextColor = [UIColor colorWithWhite:0.4 alpha:1.0f];
    
    [theme apply];
}


- (void) setDarkStyle {
    //RTE player
    if (SYSTEM_VERSION_GREATER_THAN_SEVEN) {
        
        // status bar
        [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
        
        // nav bar
        NSDictionary *navbarAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
                                          [UIColor whiteColor] ,NSForegroundColorAttributeName, nil];
        [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
        [[UINavigationBar appearance] setBarTintColor:[UIColor colorWithRed:22.0f/255.0f green:21.0f/255.0f blue:19.0f/255.0f alpha:1.0f]];
        [[UINavigationBar appearance] setTitleTextAttributes:navbarAttributes];
    }
    
    ZDKTheme *theme = [ZDKTheme baseTheme];
    
    theme.primaryTextColor = [UIColor colorWithRed:252.0f/255.0f green:204.0f/255.0f blue:1.0f/255.0f alpha:1.0f];
    theme.primaryBackgroundColor = [UIColor colorWithRed:30.0f/255.0f green:29.0f/255.0f blue:29.0f/255.0f alpha:1.0f];
    theme.secondaryBackgroundColor = [UIColor colorWithRed:22.0f/255.0f green:21.0f/255.0f blue:19.0f/255.0f alpha:1.0f];
    theme.emptyBackgroundColor = [UIColor colorWithRed:30.0f/255.0f green:29.0f/255.0f blue:29.0f/255.0f alpha:1.0f];
    theme.metaTextColor = [UIColor colorWithRed:130.0f/255.0f green:130.0f/255.0f blue:130.0f/255.0f alpha:1.0f];
    theme.separatorColor = [UIColor colorWithRed:58.0f/255.0f green:56.0f/255.0f blue:57.0f/255.0f alpha:1.0f];
    theme.inputFieldTextColor = [UIColor colorWithRed:254.0f/255.0f green:254.0f/255.0f blue:254.0f/255.0f alpha:1.0f];
    theme.inputFieldBackgroundColor = [UIColor colorWithRed:30.0f/255.0f green:28.0f/255.0f blue:29.0f/255.0f alpha:1.0f];
    
    [theme apply];
}


- (void) setLightStyle {
    //Deezer
    if (SYSTEM_VERSION_GREATER_THAN_SEVEN) {
        
        // status bar
        [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
        
        // nav bar
        NSDictionary *navbarAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
                                          [UIColor whiteColor] ,NSForegroundColorAttributeName, nil];
        [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
        [[UINavigationBar appearance] setBarTintColor:[UIColor colorWithRed:50.0f/255.0f green:50.0f/255.0f blue:61.0f/255.0f alpha:1.0f]];
        
        
        [[UINavigationBar appearance] setTitleTextAttributes:navbarAttributes];
    }
    
    ZDKTheme *theme = [ZDKTheme baseTheme];
    
    theme.primaryTextColor = [UIColor colorWithRed:34.0f/255.0f green:34.0f/255.0f blue:48.0f/255.0f alpha:1.0f];
    theme.primaryBackgroundColor = [UIColor colorWithRed:248.0f/255.0f green:248.0f/255.0f blue:249.0f/255.0f alpha:1.0f];
    theme.secondaryBackgroundColor = [UIColor colorWithRed:255.0f/255.0f green:255.0f/255.0f blue:255.0f/255.0f alpha:1.0f];
    theme.emptyBackgroundColor = [UIColor colorWithRed:248.0f/255.0f green:248.0f/255.0f blue:249.0f/255.0f alpha:1.0f];
    theme.metaTextColor = [UIColor colorWithRed:139.0f/255.0f green:139.0f/255.0f blue:150.0f/255.0f alpha:1.0f];
    theme.separatorColor = [UIColor colorWithRed:237.0f/255.0f green:237.0f/255.0f blue:241.0f/255.0f alpha:1.0f];
    theme.inputFieldTextColor = [UIColor colorWithRed:47.0f/255.0f green:46.0f/255.0f blue:63.0f/255.0f alpha:1.0f];
    theme.inputFieldBackgroundColor = [UIColor colorWithRed:255.0f/255.0f green:255.0f/255.0f blue:255.0f/255.0f alpha:1.0f];
    
    [theme apply];
}


- (void) setDarkNeoStyle {
    //inVision
    NSString * fontName = @"AppleSDGothicNeo-Light";
    
    if (SYSTEM_VERSION_GREATER_THAN_SEVEN) {
        
        // status bar
        [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
        
        [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
        [[UINavigationBar appearance] setBarTintColor:[UIColor colorWithRed:37.0f/255.0f green:43.0f/255.0f blue:51.0f/255.0f alpha:1.0f]];
        //[[UINavigationBar appearance] setBackgroundColor:[UIColor colorWithRed:1 green:0 blue:0 alpha:1]];
        [[UINavigationBar appearance] setTitleTextAttributes:
         [NSDictionary dictionaryWithObjectsAndKeys:
          [UIColor whiteColor], NSForegroundColorAttributeName,
          [UIFont fontWithName:fontName size:16.0], NSFontAttributeName,nil]];
        
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        [[UIBarButtonItem appearanceWhenContainedIn:[UINavigationBar class], nil] setTitleTextAttributes:
         @{UITextAttributeTextColor:[UIColor whiteColor],
           UITextAttributeTextShadowOffset:[NSValue valueWithUIOffset:UIOffsetMake(0, 1)],
           UITextAttributeTextShadowColor:[UIColor blackColor],
           UITextAttributeFont:[UIFont fontWithName:fontName size:16.0]
           }forState:UIControlStateNormal];
        
#pragma clang diagnostic pop

        
        
    }
    
    ZDKTheme *theme = [ZDKTheme baseTheme];
    
    theme.primaryTextColor = [UIColor colorWithRed:255.0f/255.0f green:255.0f/255.0f blue:255.0f/255.0f alpha:1.0f];
    theme.primaryBackgroundColor = [UIColor colorWithRed:27.0f/255.0f green:29.0f/255.0f blue:35.0f/255.0f alpha:1.0f];
    theme.secondaryBackgroundColor = [UIColor colorWithRed:31.0f/255.0f green:34.0f/255.0f blue:39.0f/255.0f alpha:1.0f];
    theme.emptyBackgroundColor = [UIColor colorWithRed:27.0f/255.0f green:29.0f/255.0f blue:35.0f/255.0f alpha:1.0f];
    theme.metaTextColor = [UIColor colorWithRed:126.0f/255.0f green:132.0f/255.0f blue:143.0f/255.0f alpha:1.0f];
    theme.separatorColor = [UIColor colorWithRed:105.0f/255.0f green:110.0f/255.0f blue:120.0f/255.0f alpha:1.0f];
    theme.inputFieldTextColor = [UIColor colorWithRed:255.0f/255.0f green:255.0f/255.0f blue:255.0f/255.0f alpha:1.0f];
    theme.inputFieldBackgroundColor = [UIColor colorWithRed:37.0f/255.0f green:43.0f/255.0f blue:51.0f/255.0f alpha:1.0f];
    
    theme.fontName = fontName;
    
    [theme apply];
}

@end
