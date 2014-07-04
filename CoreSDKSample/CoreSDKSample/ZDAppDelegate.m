//
//  ZDAppDelegate.m
//  CoreSDKSample
//
//  Created by Zendesk on 23/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDAppDelegate.h"
#import "ZDCoreSDKSampleViewController.h"
#import <ZendeskSDK/ZDCoreSDK.h>


@implementation ZDAppDelegate


- (BOOL) application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
{
    [ZDDispatcher setDebugLogging:YES];

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Basic SDK config
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    [ZDCoreSDK configure:^(ZDAccount *account, ZDRequestCreationConfig *requestCreationConfig) {

        // set the zendesk account
        account.subdomain = @"yoursubdomain.zendesk.com";
    }];

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // OPTIONAL - you can choose to set tags or additional info at any stage
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    [ZDCoreSDK configure:^(ZDAccount *account, ZDRequestCreationConfig *requestCreationConfig) {

        // specify any additional tags desired
        requestCreationConfig.tags = [NSArray arrayWithObjects:@"tag_one", @"tag_two", nil];

        // add some custom content to the description, followed by the device info
        NSString *additionalText = @"Some sample extra content.";

        NSString *txt = [NSString stringWithFormat:@"%@%@\n\n%@",
                         [requestCreationConfig contentSeperator],
                         additionalText,
                         [ZDDeviceInfo deviceInfoString]];

        requestCreationConfig.additionalRequestInfo = txt;
    }];


    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // OPTIONAL - Customize appearance
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    // request creation screen
    [[ZDCoreCreateRequestView appearance] setPlaceholderTextColor:[UIColor lightGrayColor]];
    [[ZDCoreCreateRequestView appearance] setTextEntryColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDCoreCreateRequestView appearance] setBgColor:[UIColor whiteColor]];
    [[ZDCoreCreateRequestView appearance] setTextEntryFont:[UIFont systemFontOfSize:12.0f]];

    UIActivityIndicatorView *spinner = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, 20, 20)];
    spinner.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
    [[ZDCoreCreateRequestView appearance] setSpinner:(id<ZDSpinnerDelegate>)spinner];

    // request list
    [[ZDRequestListTable appearance] setTableBackgroundColor:[UIColor clearColor]];
    [[ZDRequestListTable appearance] setCellSeparatorColor:[UIColor colorWithWhite:0.90f alpha:1.0f]];

    // loading cell
    spinner = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, 20, 20)];
    spinner.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
    [[ZDRequestListLoadingTableCell appearance] setSpinner:(id<ZDSpinnerDelegate>)spinner];

    // request list cells
    [[ZDRequestListTableCell appearance] setDescriptionFont:[UIFont systemFontOfSize:15]];
    [[ZDRequestListTableCell appearance] setCreatedAtFont:[UIFont systemFontOfSize:13]];
    [[ZDRequestListTableCell appearance] setUnreadColor:[UIColor colorWithRed:0.47059 green:0.6392 blue:0 alpha:1.0]];
    [[ZDRequestListTableCell appearance] setDescriptionColor:[UIColor colorWithWhite:0.26f alpha:1.0f]];
    [[ZDRequestListTableCell appearance] setCreatedAtColor:[UIColor colorWithWhite:0.54f alpha:1.0f]];
    [[ZDRequestListTableCell appearance] setVerticalMargin:20.0f];
    [[ZDRequestListTableCell appearance] setDescriptionTimestampMargin:5.0f];
    [[ZDRequestListTableCell appearance] setLeftInset:25.0f];
    [[ZDRequestListTableCell appearance] setCellBackgroundColor:[UIColor whiteColor]];

    // no requests cell
    [[ZDRequestListEmptyTableCell appearance] setMessageFont:[UIFont systemFontOfSize:11.0f]];
    [[ZDRequestListEmptyTableCell appearance] setMessageColor:[UIColor colorWithWhite:0.3f alpha:1.0f]];

    // request list error cell
    [[ZDRequestListErrorTableCell appearance] setErrorFont:[UIFont systemFontOfSize:11.0f]];
    [[ZDRequestListErrorTableCell appearance] setErrorColor:[UIColor colorWithRed:0.8f green:0.0f blue:0.0f alpha:0.8f]];
    [[ZDRequestListErrorTableCell appearance] setRetryButtonFont:[UIFont systemFontOfSize:11.0f]];
    [[ZDRequestListErrorTableCell appearance] setRetryButtonColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDRequestListErrorTableCell appearance] setRetryButtonBackgroundColor:[UIColor whiteColor]];
    [[ZDRequestListErrorTableCell appearance] setRetryButtonBorderColor:[UIColor colorWithWhite:0.8470f alpha:1.0f]];

    // comments list agent comment cells
    [[ZDAgentCommentTableCell appearance] setAvatarSize:40.0f];
    [[ZDAgentCommentTableCell appearance] setAgentNameFont:[UIFont systemFontOfSize:14.0f]];
    [[ZDAgentCommentTableCell appearance] setAgentNameColor:[UIColor colorWithWhite:0.25f alpha:1.0f]];
    [[ZDAgentCommentTableCell appearance] setTimestampFont:[UIFont systemFontOfSize:11.0f]];
    [[ZDAgentCommentTableCell appearance] setTimestampColor:[UIColor colorWithWhite:0.721f alpha:1.0f]];
    [[ZDAgentCommentTableCell appearance] setBodyFont:[UIFont systemFontOfSize:15.0f]];
    [[ZDAgentCommentTableCell appearance] setBodyColor:[UIColor colorWithWhite:0.38f alpha:1.0f]];
    [[ZDAgentCommentTableCell appearance] setCellBackground:[UIColor whiteColor]];

    // comments list end user comment cells
    [[ZDEndUserCommentTableCell appearance] setTimestampFont:[UIFont systemFontOfSize:11.0f]];
    [[ZDEndUserCommentTableCell appearance] setTimestampColor:[UIColor colorWithWhite:0.721f alpha:1.0f]];
    [[ZDEndUserCommentTableCell appearance] setBodyFont:[UIFont systemFontOfSize:15.0f]];
    [[ZDEndUserCommentTableCell appearance] setBodyColor:[UIColor colorWithWhite:0.38f alpha:1.0f]];
    [[ZDEndUserCommentTableCell appearance] setCellBackground:[UIColor colorWithWhite:0.976f alpha:1.0f]];

    // comment entry area
    [[ZDCommentEntryView appearance] setTopBorderColor:[UIColor colorWithWhite:0.831f alpha:1.0f]];
    [[ZDCommentEntryView appearance] setTextEntryFont:[UIFont systemFontOfSize:15]];
    [[ZDCommentEntryView appearance] setTextEntryColor:[UIColor colorWithWhite:0.4f alpha:1.0f]];
    [[ZDCommentEntryView appearance] setTextEntryBackgroundColor:[UIColor colorWithWhite:0.945f alpha:1.0f]];
    [[ZDCommentEntryView appearance] setTextEntryBorderColor:[UIColor colorWithWhite:0.831f alpha:1.0f]];
    [[ZDCommentEntryView appearance] setSendButtonFont:[UIFont systemFontOfSize:12]];
    [[ZDCommentEntryView appearance] setSendButtonColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDCommentEntryView appearance] setAreaBackgroundColor:[UIColor whiteColor]];


    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // Sample app boilerplate
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

    self.window.backgroundColor = [UIColor colorWithWhite:0.94f alpha:1.0f];
    
    // top view controller
    ZDCoreSDKSampleViewController *vc = [[ZDCoreSDKSampleViewController alloc] initWithNibName:nil bundle:nil];
    
    // nav controller
    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:vc];
    navController.modalTransitionStyle = UIModalTransitionStyleCoverVertical;
    
    // assign nav controller as root
    self.window.rootViewController = navController;
    
    // make key window
    [self.window makeKeyAndVisible];
    
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


@end

