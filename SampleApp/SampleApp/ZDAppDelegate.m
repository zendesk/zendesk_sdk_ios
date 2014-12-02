//
//  ZDAppDelegate.m
//  SampleApp
//
//  Created by Zendesk on 23/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDAppDelegate.h"
#import "ZDSampleViewController.h"
#import <ZendeskSDK/ZendeskSDK.h>


@implementation ZDAppDelegate


- (BOOL) application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
{
    [ZDKDispatcher setDebugLogging:YES];
    
    [ZDKLogger enable:YES];

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // OPTIONAL - you can choose to set tags or additional info at any stage
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    [ZDKRequests configure:^(ZDKAccount *account, ZDKRequestCreationConfig *requestCreationConfig) {

        // specify any additional tags desired
        requestCreationConfig.tags = [NSArray arrayWithObjects:@"tag_one", @"tag_two", nil];

        // add some custom content to the description
        NSString *additionalText = @"Some sample extra content.";

        NSString *txt = [NSString stringWithFormat:@"%@%@",
                         [requestCreationConfig contentSeperator],
                         additionalText];

        requestCreationConfig.additionalRequestInfo = txt;
    }];


    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // OPTIONAL - Customize appearance
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    // request creation screen
    [[ZDKCreateRequestView appearance] setPlaceholderTextColor:[UIColor lightGrayColor]];
    [[ZDKCreateRequestView appearance] setTextEntryColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDKCreateRequestView appearance] setViewBackgroundColor:[UIColor whiteColor]];
    [[ZDKCreateRequestView appearance] setTextEntryFont:[UIFont systemFontOfSize:12.0f]];

    [[ZDKCreateRequestView appearance] setAutomaticallyHideNavBarOnLandscape:1];
    UIActivityIndicatorView *spinner = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, 20, 20)];
    
    spinner.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
    [[ZDKCreateRequestView appearance] setSpinner:(id<ZDKSpinnerDelegate>)spinner];

    // request list
    [[ZDKRequestListTable appearance] setTableBackgroundColor:[UIColor clearColor]];
    [[ZDKRequestListTable appearance] setCellSeparatorColor:[UIColor colorWithWhite:0.90f alpha:1.0f]];

    // loading cell
    spinner = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, 20, 20)];
    spinner.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
    [[ZDRequestListLoadingTableCell appearance] setSpinner:(id<ZDKSpinnerDelegate>)spinner];

    // request list cells
    [[ZDKRequestListTableCell appearance] setDescriptionFont:[UIFont systemFontOfSize:15]];
    [[ZDKRequestListTableCell appearance] setCreatedAtFont:[UIFont systemFontOfSize:13]];
    [[ZDKRequestListTableCell appearance] setUnreadColor:[UIColor colorWithRed:0.47059 green:0.6392 blue:0 alpha:1.0]];
    [[ZDKRequestListTableCell appearance] setDescriptionColor:[UIColor colorWithWhite:0.26f alpha:1.0f]];
    [[ZDKRequestListTableCell appearance] setCreatedAtColor:[UIColor colorWithWhite:0.54f alpha:1.0f]];
    [[ZDKRequestListTableCell appearance] setVerticalMargin:20.0f];
    [[ZDKRequestListTableCell appearance] setDescriptionTimestampMargin:5.0f];
    [[ZDKRequestListTableCell appearance] setLeftInset:25.0f];
    [[ZDKRequestListTableCell appearance] setCellBackgroundColor:[UIColor whiteColor]];

    // no requests cell
    [[ZDRequestListEmptyTableCell appearance] setMessageFont:[UIFont systemFontOfSize:11.0f]];
    [[ZDRequestListEmptyTableCell appearance] setMessageColor:[UIColor colorWithWhite:0.3f alpha:1.0f]];

    // comments list agent comment cells
    [[ZDKAgentCommentTableCell appearance] setAvatarSize:40.0f];
    [[ZDKAgentCommentTableCell appearance] setAgentNameFont:[UIFont systemFontOfSize:14.0f]];
    [[ZDKAgentCommentTableCell appearance] setAgentNameColor:[UIColor colorWithWhite:0.25f alpha:1.0f]];
    [[ZDKAgentCommentTableCell appearance] setTimestampFont:[UIFont systemFontOfSize:11.0f]];
    [[ZDKAgentCommentTableCell appearance] setTimestampColor:[UIColor colorWithWhite:0.721f alpha:1.0f]];
    [[ZDKAgentCommentTableCell appearance] setBodyFont:[UIFont systemFontOfSize:15.0f]];
    [[ZDKAgentCommentTableCell appearance] setBodyColor:[UIColor colorWithWhite:0.38f alpha:1.0f]];
    [[ZDKAgentCommentTableCell appearance] setCellBackground:[UIColor whiteColor]];

    // comments list end user comment cells
    [[ZDKEndUserCommentTableCell appearance] setTimestampFont:[UIFont systemFontOfSize:11.0f]];
    [[ZDKEndUserCommentTableCell appearance] setTimestampColor:[UIColor colorWithWhite:0.721f alpha:1.0f]];
    [[ZDKEndUserCommentTableCell appearance] setBodyFont:[UIFont systemFontOfSize:15.0f]];
    [[ZDKEndUserCommentTableCell appearance] setBodyColor:[UIColor colorWithWhite:0.38f alpha:1.0f]];
    [[ZDKEndUserCommentTableCell appearance] setCellBackground:[UIColor colorWithWhite:0.976f alpha:1.0f]];

    // comments list loading cell
    spinner = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, 20, 20)];
    spinner.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
    [[ZDKCommentsListLoadingTableCell appearance] setSpinner:(id<ZDKSpinnerDelegate>)spinner];
    [[ZDKCommentsListLoadingTableCell appearance] setCellBackground:[UIColor whiteColor]];
    [[ZDKCommentsListLoadingTableCell appearance] setLeftInset:25.0f];

    
    // comment entry area
    [[ZDKCommentEntryView appearance] setTopBorderColor:[UIColor colorWithWhite:0.831f alpha:1.0f]];
    [[ZDKCommentEntryView appearance] setTextEntryFont:[UIFont systemFontOfSize:15]];
    [[ZDKCommentEntryView appearance] setTextEntryColor:[UIColor colorWithWhite:0.4f alpha:1.0f]];
    [[ZDKCommentEntryView appearance] setTextEntryBackgroundColor:[UIColor colorWithWhite:0.945f alpha:1.0f]];
    [[ZDKCommentEntryView appearance] setTextEntryBorderColor:[UIColor colorWithWhite:0.831f alpha:1.0f]];
    [[ZDKCommentEntryView appearance] setSendButtonFont:[UIFont systemFontOfSize:12]];
    [[ZDKCommentEntryView appearance] setSendButtonColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDKCommentEntryView appearance] setAreaBackgroundColor:[UIColor whiteColor]];

    //Rate My App
    [[ZDKRMADialogView appearance] setHeaderBackgroundColor:[UIColor whiteColor]];
    [[ZDKRMADialogView appearance] setHeaderColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDKRMADialogView appearance] setHeaderFont:[UIFont systemFontOfSize:16.0f]];
    [[ZDKRMADialogView appearance] setButtonBackgroundColor:[UIColor colorWithWhite:0.9451f alpha:1.0f]];
    [[ZDKRMADialogView appearance] setButtonSelectedBackgroundColor:[UIColor whiteColor]];
    [[ZDKRMADialogView appearance] setButtonColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDKRMADialogView appearance] setButtonFont:[UIFont systemFontOfSize:14.0f]];
    [[ZDKRMADialogView appearance] setSeparatorLineColor:[UIColor colorWithWhite:0.8470f alpha:1.0f]];
    
    // style thefeedback view
    [[ZDKRMAFeedbackView appearance] setHeaderFont:[UIFont systemFontOfSize:16.0f]];
    [[ZDKRMAFeedbackView appearance] setSubheaderFont:[UIFont systemFontOfSize:12.0f]];
    [[ZDKRMAFeedbackView appearance] setSeparatorLineColor:[UIColor colorWithWhite:0.8470f alpha:1.0f]];
    [[ZDKRMAFeedbackView appearance] setButtonBackgroundColor:[UIColor colorWithWhite:0.9451f alpha:1.0f]];
    [[ZDKRMAFeedbackView appearance] setButtonColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDKRMAFeedbackView appearance] setButtonSelectedColor:[UIColor colorWithWhite:0.2627f alpha:0.3f]];
    [[ZDKRMAFeedbackView appearance] setButtonFont:[UIFont systemFontOfSize:14.0f]];
    [[ZDKRMAFeedbackView appearance] setTextEntryFont:[UIFont systemFontOfSize:12.0f]];
    
    
    // style the help center
    [[ZDKSupportView appearance] setBackgroundColor:[UIColor colorWithWhite:0.94f alpha:1.0f]];
    [[ZDKSupportView appearance] setTableBackgroundColor:[UIColor whiteColor]];
    [[ZDKSupportView appearance] setSearchBarStyle:UIBarStyleDefault];
    [[ZDKSupportView appearance] setSeparatorColor:[UIColor lightGrayColor]];
    [[ZDKSupportView appearance] setNoResultsFoundLabelFont:[UIFont systemFontOfSize:14.0f]];
    [[ZDKSupportView appearance] setNoResultsFoundLabelColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDKSupportView appearance] setNoResultsFoundLabelBackground:[UIColor colorWithWhite:0.94f alpha:1.0f]];
    [[ZDKSupportView appearance] setNoResultsContactButtonBackground:[UIColor colorWithWhite:0.94f alpha:1.0f]];
    [[ZDKSupportView appearance] setNoResultsContactButtonBorderColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDKSupportView appearance] setNoResultsContactButtonBorderWidth:1.0f];
    [[ZDKSupportView appearance] setNoResultsContactButtonCornerRadius:4.0f];
    [[ZDKSupportView appearance] setNoResultsFoundLabelFont:[UIFont systemFontOfSize:14.0f]];
    [[ZDKSupportView appearance] setNoResultsContactButtonEdgeInsets:UIEdgeInsetsMake(12, 22, 12, 22)];
    [[ZDKSupportView appearance] setNoResultsContactButtonTitleColorNormal:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDKSupportView appearance] setNoResultsContactButtonTitleColorHighlighted:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDKSupportView appearance] setNoResultsContactButtonTitleColorDisabled:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    
    //HC search cell
    [[ZDKSupportTableViewCell appearance] setBackgroundColor:[UIColor whiteColor]];
    [[ZDKSupportTableViewCell appearance] setTitleLabelBackground:[UIColor whiteColor]];
    [[ZDKSupportTableViewCell appearance] setTitleLabelColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDKSupportTableViewCell appearance] setTitleLabelFont:[UIFont systemFontOfSize:18.0f]];

    [[ZDKSupportArticleTableViewCell appearance] setBackgroundColor:[UIColor whiteColor]];
    [[ZDKSupportArticleTableViewCell appearance] setArticleParentsLabelFont:[UIFont systemFontOfSize:12.0f]];
    [[ZDKSupportArticleTableViewCell appearance] setArticleParentsLabelColor:[UIColor lightGrayColor]];
    [[ZDKSupportArticleTableViewCell appearance] setArticleParnetsLabelBackground:[UIColor whiteColor]];
    [[ZDKSupportArticleTableViewCell appearance] setTitleLabelFont:[UIFont systemFontOfSize:18.0f]];
    [[ZDKSupportArticleTableViewCell appearance] setTitleLabelColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDKSupportArticleTableViewCell appearance] setTitleLabelBackground:[UIColor whiteColor]];
    
    [[ZDKSupportAttachmentCell appearance] setBackgroundColor:[UIColor colorWithWhite:0.94f alpha:1.0f]];
    [[ZDKSupportAttachmentCell appearance] setTitleLabelBackground:[UIColor colorWithWhite:0.94f alpha:1.0f]];
    [[ZDKSupportAttachmentCell appearance] setTitleLabelColor:[UIColor colorWithWhite:0.2627f alpha:1.0f]];
    [[ZDKSupportAttachmentCell appearance] setTitleLabelFont:[UIFont systemFontOfSize:12.0f]];
    [[ZDKSupportAttachmentCell appearance] setFileSizeLabelBackground:[UIColor colorWithWhite:0.94f alpha:1.0f]];
    [[ZDKSupportAttachmentCell appearance] setFileSizeLabelColor:[UIColor grayColor]];
    [[ZDKSupportAttachmentCell appearance] setFileSizeLabelFont:[UIFont systemFontOfSize:12.0f]];



    
   
    UIActivityIndicatorView *rmaSpinner = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(0, 0, 20, 20)];
    spinner.activityIndicatorViewStyle = UIActivityIndicatorViewStyleGray;
    [[ZDKRMAFeedbackView appearance] setSpinner:(id<ZDKSpinnerDelegate>)rmaSpinner];
    

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

