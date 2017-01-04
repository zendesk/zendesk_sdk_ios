/*
 *
 *  ZDKRequests.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 22/04/2014.  
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
@property (copy) NSArray *tags;


/**
 * Additional free text to be appended to the request description.
 */
@property (copy) NSString *additionalRequestInfo;

/**
 *  Request subject.
 *
 *  @since 1.3.0.1
 */
@property (copy) NSString *subject;


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

@end
