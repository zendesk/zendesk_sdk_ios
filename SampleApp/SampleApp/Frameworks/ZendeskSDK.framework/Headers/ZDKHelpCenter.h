/*
 *
 *  ZDKHelpCenter.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 09/09/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKHelpCenterConversationsUIDelegate.h"
#import "ZDKUIViewController.h"

@class ZDKHelpCenterOverviewContentModel;

/**
 *  Convenience class for presenting Help Center content.
 *
 *  @since 0.9.3.1
 */
@interface ZDKHelpCenter : NSObject <ZDKHelpCenterConversationsUIDelegate>

/**
 *  Pushes a Help Center Overview Screen with content defined by the ZDKHelpCenterOverviewContentModel.
 *
 *  @param navController          The navigation controller which to push onto.
 *  @param helpCenterContentModel A ZDKHelpCenterContentModel object that defines the content shown on screen
 *
 *  @since 1.7.0.1
 */
+ (void) pushHelpCenterOverview:(UINavigationController *)navController
               withContentModel:(ZDKHelpCenterOverviewContentModel *)helpCenterContentModel;

/**
 *  Presents a Help Center Overview Screen modally with content defined by the ZDKHelpCenterOverviewContentModel.
 *
 *  @param viewController         View Controller from which to present from.
 *  @param helpCenterContentModel A ZDKHelpCenterContentModel object that defines the content shown on screen
 *
 *  @since 1.7.0.1
 */
+ (void) presentHelpCenterOverview:(UIViewController *)viewController
                  withContentModel:(ZDKHelpCenterOverviewContentModel *)helpCenterContentModel;

/**
 *  Specify an icon that will be placed in the right nav bar button.
 *
 *  @since 0.9.3.1
 *
 *  @param name The name of an image in your app bundle.
 */
+ (void) setConversationsBarButtonImage:(NSString *)name __deprecated_msg("Deprecated as of 1.10.0.1, use ZDKHelpCenterConversationsUIDelegate instead.");


/**
 *  Set the nav bar UI type for displaying the conversations screen.
 *
 *  @since 0.9.3.1
 *
 *  @param uiType A ZDKNavBarConversationsUIType.
 */
+ (void) setNavBarConversationsUIType:(ZDKNavBarConversationsUIType)uiType __deprecated_msg("Deprecated as of 1.10.0.1, use ZDKHelpCenterConversationsUIDelegate instead.");


/**
 Set a delegate which will be forwarded to Help Center view controllers.
 Replaces `setConversationsBarButtonImage:` and `setNavBarConversationsUIType:`
 as the means to customize the right navigation bar button functionality.

 @since 1.10.0.1
 
 @param delegate Implementation of ZDKHelpCenterConversationsUIDelegate.
 */
+ (void) setUIDelegate:(id<ZDKHelpCenterConversationsUIDelegate>)delegate;

@end
