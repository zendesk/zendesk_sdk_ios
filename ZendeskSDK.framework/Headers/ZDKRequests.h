/*
 *
 *  ZDKRequests.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 22/04/2014.  
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


#import "ZDKCreateRequestUIDelegate.h"
#import "ZDKUIViewController.h"



@class ZDKRequestListTable;
@class ZDKAccount;


typedef void (^ZDKRequestSuccess) (id result);
typedef void (^ZDKRequestError) (NSError *error);


#pragma mark Request creation config


/**
 * Request creation config object.
 */
@interface ZDKRequestCreationConfig : NSObject {

    NSArray *tags;
    NSString *additionalRequestInfo;
    NSString *subject;

}


/**
 * Tags to be included when creating a request.
 */
@property (strong) NSArray *tags;


/**
 * Additional free text to be appended to the request description.
 */
@property (strong) NSString *additionalRequestInfo;

/**
 *  Request subject.
 *
 *  @since 1.3.0.1
 */
@property (strong) NSString *subject;


/**
 * Helper method providing a simple visual separator for request info including line breaks.
 * @return @"\n\n";
 */
- (NSString*) contentSeperator;


@end


#pragma mark - ZDKRequests


/**
 * Config block.
 * @param account the account on which the subdomain and user can be set
 * @param requestCreationConfig the Request creation config which can be updated as desired.
 */
typedef void (^ZDSDKConfigBlock) (ZDKAccount *account, ZDKRequestCreationConfig *requestCreationConfig);


/**
 * Core SDK class providing access to request deflection, creation and lists.
 */
@interface ZDKRequests : NSObject  <ZDKCreateRequestUIDelegate> {

    ZDKRequestCreationConfig *requestCreationConfig;

}


/**
 * Request creation config for this instance.
 */
@property (strong) ZDKRequestCreationConfig *requestCreationConfig;


/**
 * Get the instance of ZDKRequests
 * @return ZDKRequests A shared instance of ZDKRequests
 */
+ (instancetype) instance;


/**
 * Configure the SDK
 * @param config the config block with which to setup the SDK.
 */
+ (void) configure:(ZDSDKConfigBlock)config;

/**
 *  Presents a simple request creation on top of the provided view controller modally.
 *
 *  @param viewController A view controller frow which to present on.
 *
 *  @since 1.6.0.1
 */
+ (void) presentRequestCreationWithViewController:(UIViewController *)viewController;

/**
 *  Presents a request list view controller modally on top of the provided view controller modally.
 *
 *  @param viewController A view controller frow which to present on.
 *
 *  @since 1.6.0.1
 */
+ (void) presentRequestListWithViewController:(UIViewController *)viewController;

/**
 *  Pushes a request list view controller on top of the navigation stack.
 *
 *  @param navController The UINavitgationController which to push from.
 *  @param aGuide        Should the request list respect top and bottom layout guide? Pass in
 *                       one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                       ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 *
 *  @since 1.6.0.1
 */
+ (void) pushRequestListWithNavigationController:(UINavigationController *)navController layoutGuide:(ZDKLayoutGuide)aGuide;

/**
 *  Pushes a request list view controller on top of the navigation stack.
 *
 *  @param navController The UINavitgationController which to push from.
 *
 *  @since 1.6.0.1
 */
+ (void) pushRequestListWithNavigationController:(UINavigationController *)navController;


/**
 *  Specify an icon that will be placed in the right nav bar button.
 *
 *  @param name The name of an image in your app bundle.
 */
+ (void) setNewRequestBarButtonImage:(NSString *)name;


/**
 *  Set the nav bar UI type for displaying the create request screen.
 *
 *  @param uiType A ZDKNavBarCreateRequestUIType.
 */
+ (void) setNavBarCreateRequestUIType:(ZDKNavBarCreateRequestUIType)uiType;

// Deprecated Methods

/**
 *  Displays a simple request creation modal. The modal is presented on top the view controller
 *  that is passed in.
 *
 *  @param navController The UINavigationController from which to present the request creation view.
 *  @param success       A block that is executed on successful submission of a request.
 *  @param error         A block that is executed when an error occurs during submission of a request.
 */
+ (void) showRequestCreationWithNavController:(UINavigationController*)navController
                                  withSuccess:(ZDKRequestSuccess)success
                                     andError:(ZDKRequestError)error __deprecated_msg("As of version 1.6.0.1 use +presentRequestCreationWithViewController: instead");

/**
 *  Displays a simple request creation modal.
 *
 *  @param navController The UINavigationController from which the controller is pushed.
 */
+ (void) showRequestCreationWithNavController:(UINavigationController*)navController  __deprecated_msg("As of version 1.6.0.1 use +presentRequestCreationWithViewController: instead");

/**
 *  Displays a request list view controller.
 *
 *  @since 1.2.0.1
 *
 *  @param navController A navigation controller from which to push the request list view.
 *  @param aGuide        Should the request list respect top and bottom layout guide? Pass in
 *                       one of the const values, ZDKLayoutRespectAll, ZDKLayoutRespectNone,
 *                       ZDKLayoutRespectTop and ZDKLayoutRespectBottom.
 */
+ (void) showRequestListWithNavController:(UINavigationController *)navController layoutGuide:(ZDKLayoutGuide)aGuide  __deprecated_msg("As of version 1.6.0.1 use +pushRequestListWithNavigationController: instead");

/**
 *  Displays a request list view controller modally.
 *
 *  @param navController A navigation controller from which to push the request list view.
 */
+ (void) presentRequestListWithNavController:(UINavigationController *)navController  __deprecated_msg("As of version 1.6.0.1 use +presentRequestListWithViewController: instead");

/**
 *  Displays a request list view controller.
 *
 *  @param navController A navigation controller from which to push the request list view.
 */
+ (void) showRequestListWithNavController:(UINavigationController *)navController  __deprecated_msg("As of version 1.6.0.1 use +pushRequestListWithNavigationController: instead");


@end
