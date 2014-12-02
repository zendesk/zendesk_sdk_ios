/*
 *
 *  ZDKHelpCenter.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 09/09/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>
#import "ZDKHelpCenterConversationsUIDelegate.h"


@interface ZDKHelpCenter : NSObject <ZDKHelpCenterConversationsUIDelegate>



/**
 *  Displays the Help Center view on top the view controller that is passed in.
 *
 *  @param navController The UINavigationController from which to pressent the request creation view.
 */
+ (void) showHelpCenterWithNavController:(UINavigationController*)navController;


/**
 *  Displays the Help Center view on top of the view controller that is passed in.
 *
 *  @param navController The UINavigationController from which to pressent the request creation view.
 *  @param labels        Array of labels. Articles containing only these labels are displayed.
 */
+ (void) showHelpCenterWithNavController:(UINavigationController *)navController filterByArticleLabels:(NSArray *)labels;


/**
 *  Specify an icon that will be placed in the right nav bar button.
 *
 *  @param name The name of an image in your app bundle.
 */
+ (void) setConversationsBarButtonImage:(NSString *)name;


/**
 *  Set the nav bar UI type for displaying the conversations screen.
 *
 *  @param uiType A ZDKNavBarConversationsUIType.
 */
+ (void) setNavBarConversationsUIType:(ZDKNavBarConversationsUIType)uiType;


@end
