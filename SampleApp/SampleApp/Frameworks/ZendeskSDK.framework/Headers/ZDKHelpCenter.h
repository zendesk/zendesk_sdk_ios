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
               withContentModel:(ZDKHelpCenterOverviewContentModel *)helpCenterContentModel NS_AVAILABLE_IOS(8_0);

/**
 *  Presents a Help Center Overview Screen modally with content defined by the ZDKHelpCenterOverviewContentModel.
 *
 *  @param viewController         View Controller from which to present from.
 *  @param helpCenterContentModel A ZDKHelpCenterContentModel object that defines the content shown on screen
 *
 *  @since 1.7.0.1
 */
+ (void) presentHelpCenterOverview:(UIViewController *)viewController
                  withContentModel:(ZDKHelpCenterOverviewContentModel *)helpCenterContentModel NS_AVAILABLE_IOS(8_0);


/**
 *  Presents the Help Center view on top of the view controller passed in, modally.
 *
 *  @param viewController A view controller which Help Center is presented over.
 *
 *  @since 1.6.0.1
 */
+ (void) presentHelpCenterWithViewController:(UIViewController *)viewController __deprecated_msg("Deprecated as of 1.7.2.1.");

/**
 *  Pushes the Help Center view on top the navigation controller that is passed in.
 *
 *  @param navController A navigation controller which to presnt Help Center
 *
 *  @since 1.6.0.1
 */
+ (void) pushHelpCenterWithNavigationController:(UINavigationController*)navController __deprecated_msg("Deprecated as of 1.7.2.1.");

/**
 *  Presents the help center view on top of the view controller passed in, modally.
 *
 *  @param viewController The UiViewController from which to present the help center view controller.
 *  @param aGuide         Should the request list respect top and bottom layout guide? Pass in
 *                        one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                        ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 *
 *  @since 1.6.0.1
 */
+ (void) presentHelpCenterWithViewController:(UIViewController *)viewController layoutGuide:(ZDKLayoutGuide)aGuide __deprecated_msg("Deprecated as of 1.7.2.1.");

/**
 *  Pushes the Help Center view on top the navigation controller that is passed in.
 *
 *  @param navController A navigation controller which to presnt Help Center
 *  @param aGuide         Should the request list respect top and bottom layout guide? Pass in
 *                        one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                        ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 *  @since 1.6.0.1
 */
+ (void) pushHelpCenterWithNavigationController:(UINavigationController*)navController layoutGuide:(ZDKLayoutGuide)aGuide __deprecated_msg("Deprecated as of 1.7.2.1.");

/**
 *  Presents the Help Center view on top of the view controller that is passed in, modally.
 *
 *  @param viewController The UIViewController from which to present the help center view controller.
 *  @param labels         Array of labels. Articles containing only these labels are displayed.
 *  @param aGuide         Should the request list respect top and bottom layout guide? Pass in
 *                        one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                        ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 *
 *  @since 1.6.0.1
 */
+ (void) presentHelpCenterWithViewController:(UIViewController *)viewController
                       filterByArticleLabels:(NSArray *)labels
                                 layoutGuide:(ZDKLayoutGuide)aGuide __deprecated_msg("Deprecated as of 1.7.2.1.");

/**
 *  Pushes the Help Center view on top of the navigation controller that is passed in.
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 *  @param labels        Array of labels. Articles containing only these labels are displayed.
 *
 *  @since 1.6.0.1
 */
+ (void) pushHelpCenterWithNavigationController:(UINavigationController *)navController filterByArticleLabels:(NSArray *)labels __deprecated_msg("Deprecated as of 1.7.2.1.");

/**
 *  Pushes the Help Center view on top of the view controller that is passed in.
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 *  @param labels        Array of labels. Articles containing only these labels are displayed.
 *  @param aGuide        Should the request list respect top and bottom layout guide? Pass in
 *                       one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                       ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 *
 *  @since 1.6.0.1
 */
+ (void) pushHelpCenterWithNavigationController:(UINavigationController *)navController
                          filterByArticleLabels:(NSArray *)labels
                                    layoutGuide:(ZDKLayoutGuide)aGuide __deprecated_msg("Deprecated as of 1.7.2.1.");

/**
 *  Presents the Help Center articles view presented on top the view controller that is passed in, modally.
 *
 *  @param viewController The UIViewController from which to present the help centre view controller.
 *  @param sectionId      The ID of the parent Help Center section which the displayed articles belong to.
 *  @param sectionName    The sectionName to display in the title bar. The sectionName will default to "Support" if set to nil.
 *  @param aGuide         Should the request list respect top and bottom layout guide? Pass in
 *                        one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                        ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 *
 *  @since 1.6.0.1
 */
+ (void) presentHelpCenterWithViewController:(UIViewController *)viewController
                           filterBySectionId:(NSString *)sectionId
                                 sectionName:(NSString *)sectionName
                                 layoutGuide:(ZDKLayoutGuide)aGuide __deprecated_msg("Deprecated as of 1.7.2.1.");

/**
 *  Pushes the Help Center on top of the navigation controller passed in.
 *
 *  @param navController The UINavigationController from which to present the help center view controller.
 *  @param sectionId     The ID of the parent Help Center section which the displayed articles belong to.
 *  @param sectionName   The sectionName to display in the title bar. The sectionName will default to "Support" if set to nil.
 *  @param aGuide        Should the request list respect top and bottom layout guide? Pass in
 *                       one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                       ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 *  @since 1.6.0.1
 */
+ (void) pushHelpCenterWithNavigationController:(UINavigationController *)navController
                              filterBySectionId:(NSString *)sectionId
                                    sectionName:(NSString *)sectionName
                                    layoutGuide:(ZDKLayoutGuide)aGuide __deprecated_msg("Deprecated as of 1.7.2.1.");

/**
 *  Presents the Help Center articles view presented on top the view controller that is passed in, modally.
 *
 *  @param viewController The UIViewController from which to present the help centre view controller
 *  @param categoryId     The ID of the parent Help Center category which the displayed sections belong to.
 *  @param categoryName   The categoryName to display in the title bar. The categoryName will default to "Support" if set to nil.
 *  @param aGuide         Should the request list respect top and bottom layout guide? Pass in
 *                        one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                        ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 *
 *  @since 1.6.0.1
 */
+ (void) presentHelpCenterWithViewController:(UIViewController *)viewController
                          filterByCategoryId:(NSString *)categoryId
                                categoryName:(NSString *)categoryName
                                 layoutGuide:(ZDKLayoutGuide)aGuide __deprecated_msg("Deprecated as of 1.7.2.1.");

/**
 *  Pushes the Help Center view on top of the navigation controller passed in
 *
 *  @param navController The UINavigationController from which to present the help center view controller on top.
 *  @param categoryId    The ID of the parent Help Center category which the displayed sections belong to.
 *  @param categoryName  The categoryName to display in the title bar. The categoryName will default to "Support" if set to nil.
 *  @param aGuide        Should the request list respect top and bottom layout guide? Pass in
 *                       one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                       ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 *  @since 1.6.0.1
 */
+ (void) pushHelpCenterWithNavigationController:(UINavigationController *)navController
                             filterByCategoryId:(NSString *)categoryId
                                   categoryName:(NSString *)categoryName
                                    layoutGuide:(ZDKLayoutGuide)aGuide  __deprecated_msg("Deprecated as of 1.7.2.1.");

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

@end
