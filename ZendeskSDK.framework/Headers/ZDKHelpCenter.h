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
#import "ZDKUIViewController.h"

/**
 *  Convenience class for presenting Help Center content.
 *
 *  @since 0.9.3.1
 */
@interface ZDKHelpCenter : NSObject <ZDKHelpCenterConversationsUIDelegate>


/**
 *  Displays the Help Center view on top the navigation controller that is passed in.
 *
 *  @since 0.9.3.1
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 */
+ (void) showHelpCenterWithNavController:(UINavigationController*)navController;


/**
 *  Displays the Help Center view on top the navigation controller that is passed in.
 *
 *  @since 1.2.0.1
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 *  @param aGuide        Should the request list respect top and bottom layout guide? Pass in
 *                       one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                       ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 */
+ (void) showHelpCenterWithNavController:(UINavigationController*)navController layoutGuide:(ZDKLayoutGuide)aGuide;

/**
 *  Modally display the Help Center view on top the navigation controller that is passed in.
 *
 *  @since 1.1.1.1
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 */
+ (void) presentHelpCenterWithNavController:(UINavigationController*)navController;


/**
 *  Displays the Help Center view on top of the view controller that is passed in.
 *
 *  @since 0.9.3.1
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 *  @param labels        Array of labels. Articles containing only these labels are displayed.
 */
+ (void) showHelpCenterWithNavController:(UINavigationController *)navController filterByArticleLabels:(NSArray *)labels;


/**
 *  Displays the Help Center view on top of the view controller that is passed in.
 *
 *  @since 1.2.0.1
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 *  @param labels        Array of labels. Articles containing only these labels are displayed.
 *  @param aGuide        Should the request list respect top and bottom layout guide? Pass in
 *                       one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                       ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 */
+ (void) showHelpCenterWithNavController:(UINavigationController *)navController
                   filterByArticleLabels:(NSArray *)labels
                             layoutGuide:(ZDKLayoutGuide)aGuide;

/**
 *  Modally display the Help Center view on top of the navigation controller that is passed in.
 *
 *  @since 1.1.1.1
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 *  @param labels        Array of labels. Articles containing only these labels are displayed.
 */
+ (void) presentHelpCenterWithNavController:(UINavigationController *)navController filterByArticleLabels:(NSArray *)labels;


/**
 *  Specify an icon that will be placed in the right nav bar button.
 *
 *  @since 0.9.3.1
 *
 *  @param name The name of an image in your app bundle.
 */
+ (void) setConversationsBarButtonImage:(NSString *)name;


/**
 *  Set the nav bar UI type for displaying the conversations screen.
 *
 *  @since 0.9.3.1
 *
 *  @param uiType A ZDKNavBarConversationsUIType.
 */
+ (void) setNavBarConversationsUIType:(ZDKNavBarConversationsUIType)uiType;


/**
 *  Displays the Help Center sections view for a given category ID on top the navigation controller that is passed in.
 *
 *  @since 1.3.1.1
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 *  @param categoryId    The ID of the parent Help Center category which the displayed sections belong to.
 *  @param categoryName  The categoryName to display in the title bar. The categoryName will default to "Support" if set to nil.
 *  @param aGuide        Should the request list respect top and bottom layout guide? Pass in
 *                       one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                       ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 */
+ (void) showHelpCenterWithNavController:(UINavigationController *)navController
                      filterByCategoryId:(NSString *)categoryId
                            categoryName:(NSString *)categoryName
                             layoutGuide:(ZDKLayoutGuide)aGuide;


/**
 *  Displays the Help Center articles view on top the navigation controller that is passed in.
 *
 *  @since 1.3.1.1
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 *  @param sectionId     The ID of the parent Help Center section which the displayed articles belong to.
 *  @param sectionName   The sectionName to display in the title bar. The sectionName will default to "Support" if set to nil.
 *  @param aGuide        Should the request list respect top and bottom layout guide? Pass in
 *                       one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                       ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 */
+ (void) showHelpCenterWithNavController:(UINavigationController *)navController
                       filterBySectionId:(NSString *)sectionId
                             sectionName:(NSString *)sectionName
                             layoutGuide:(ZDKLayoutGuide)aGuide;

/**
 *  Modally display the Help Center view on top of the navigation controller that is passed in for a given category ID.
 *
 *  @since 1.3.1.1
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 *  @param categoryId    The ID of the parent Help Center category which the displayed sections belong to.
 *  @param categoryName  The categoryName to display in the title bar. The categoryName will default to "Support" if set to nil.
 *  @param aGuide        Should the request list respect top and bottom layout guide? Pass in
 *                       one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                       ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 */
+ (void) presentHelpCenterWithNavController:(UINavigationController *)navController
                      filterByCategoryId:(NSString *)categoryId
                            categoryName:(NSString *)categoryName
                             layoutGuide:(ZDKLayoutGuide)aGuide;


/**
 *  Modally display the Help Center view on top of the navigation controller that is passed in for a given section ID.
 *
 *  @since 1.3.1.1
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 *  @param sectionId     The ID of the parent Help Center section which the displayed articles belong to.
 *  @param sectionName   The sectionName to display in the title bar. The sectionName will default to "Support" if set to nil.
 *  @param aGuide        Should the request list respect top and bottom layout guide? Pass in
 *                       one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                       ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 */
+ (void) presentHelpCenterWithNavController:(UINavigationController *)navController
                       filterBySectionId:(NSString *)sectionId
                             sectionName:(NSString *)sectionName
                             layoutGuide:(ZDKLayoutGuide)aGuide;

@end
