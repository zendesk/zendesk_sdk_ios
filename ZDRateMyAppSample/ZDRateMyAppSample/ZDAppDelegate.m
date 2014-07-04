//
//  ZDAppDelegate.m
//  ZDRateMyAppSample
//
//  Created by Zendesk on 19/02/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDAppDelegate.h"
#import "ZDFirstViewController.h"
#import <ZendeskSDK/ZDRMA.h>


@implementation ZDAppDelegate


- (BOOL) application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
{
    NSSetUncaughtExceptionHandler(&uncaughtExceptionHandler);

    // Setup Rate My App
    [ZDRMA configure:^(ZDRMAConfigObject *config) {

        config.zendeskSubdomain = @"yoursubdomain.zendesk.com";
        config.userEmail = @"example@example.com";
        config.itunesAppId = @"1234567";

        // for the sample app set minimums to zero
        config.minimumDays = [NSNumber numberWithInt:0];
        config.minimumVisits = [NSNumber numberWithInt:0];
    }];


    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // OPTIONAL - Customize appearance
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    [ZDRMA configure:^(ZDRMAConfigObject *config) {

        // set success and error dialog images images
        config.successImageName = @"rma_tick";
        config.errorImageName = @"rma_error";
    }];

    // style the dialog view
    [[ZDRMADialogView appearance] setHeaderBackgroundColor:[UIColor whiteColor]];
    [[ZDRMADialogView appearance] setHeaderColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDRMADialogView appearance] setHeaderFont:[UIFont systemFontOfSize:16.0f]];
    [[ZDRMADialogView appearance] setButtonBackgroundColor:[UIColor colorWithWhite:0.9451f alpha:1.0f]];
    [[ZDRMADialogView appearance] setButtonSelectedBackgroundColor:[UIColor whiteColor]];
    [[ZDRMADialogView appearance] setButtonColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDRMADialogView appearance] setButtonFont:[UIFont systemFontOfSize:14.0f]];
    [[ZDRMADialogView appearance] setSeparatorLineColor:[UIColor colorWithWhite:0.8470f alpha:1.0f]];

    // style thefeedback view
    [[ZDRMAFeedbackView appearance] setHeaderFont:[UIFont systemFontOfSize:16.0f]];
    [[ZDRMAFeedbackView appearance] setSubheaderFont:[UIFont systemFontOfSize:12.0f]];
    [[ZDRMAFeedbackView appearance] setSeparatorLineColor:[UIColor colorWithWhite:0.8470f alpha:1.0f]];
    [[ZDRMAFeedbackView appearance] setButtonBackgroundColor:[UIColor colorWithWhite:0.9451f alpha:1.0f]];
    [[ZDRMAFeedbackView appearance] setButtonColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDRMAFeedbackView appearance] setButtonSelectedColor:[UIColor colorWithWhite:0.2627f alpha:0.3f]];
    [[ZDRMAFeedbackView appearance] setButtonFont:[UIFont systemFontOfSize:14.0f]];
    [[ZDRMAFeedbackView appearance] setTextEntryFont:[UIFont systemFontOfSize:12.0f]];

    UIActivityIndicatorView *spinner = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, 20, 20)];
    spinner.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
    [[ZDRMAFeedbackView appearance] setSpinner:(id<ZDSpinnerDelegate>)spinner];

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Sample app boilerplate
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // app window
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];

    // top view controller
    ZDFirstViewController *vc = [[ZDFirstViewController alloc] initWithNibName:nil bundle:nil];

    // nav controller
    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:vc];

    // assign nav controller as root
    self.window.rootViewController = navController;

    // make key window
    [self.window makeKeyAndVisible];

    // log the app opening
    [ZDRMA logVisit];
    
    if (SYSTEM_VERSION_GREATER_THAN_SEVEN) {
        
        // status bar
        [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent];
        
        // nav bar
        NSDictionary *navbarAttributes = [NSDictionary dictionaryWithObjectsAndKeys:
                                          [UIColor whiteColor] ,UITextAttributeTextColor, nil];
        [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
        [[UINavigationBar appearance] setBarTintColor:[UIColor colorWithRed:0.4705f green:0.6392f blue:0.0f alpha:1.0f]];
        [[UINavigationBar appearance] setTitleTextAttributes:navbarAttributes];
    }
    
    return YES;
}


- (void) applicationWillEnterForeground:(UIApplication*)application
{
    // log the app forground event
    [ZDRMA logVisit];
}


void uncaughtExceptionHandler(NSException *exception) {
    NSLog(@"CRASH: %@", exception);
    NSLog(@"Stack Trace: %@", [exception callStackSymbols]);
}


@end

