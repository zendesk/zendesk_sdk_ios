//
//  CoreSDK.h
//  CoreSDK
//
//  Created by Zendesk on 22/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "ZDAPI.h"
#import "ZDUI.h"
#import "ZDCoreCreateRequestViewController.h"
#import "ZDRequestListTableCell.h"
#import "ZDRequestListTable.h"
#import "ZDRequestCommentsViewController.h"
#import "ZDRequestCommentsView.h"
#import "ZDRequestCommentsTable.h"
#import "ZDCommentEntryView.h"
#import "ZDRequestCommentTableCell.h"


#pragma mark Request creation config


/**
 * Request creation config object.
 */
@interface ZDRequestCreationConfig : NSObject {

    NSArray *tags;
    NSString *additionalRequestInfo;

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
 * Helper method providing a simple visual separator for request info including line breaks.
 * @return @"\n\n---------------------------------------------------------------------------------\n";
 */
- (NSString*) contentSeperator;


@end


#pragma mark - CoreSDK


/**
 * Config block.
 * @param account the account on which the subdomain and user can be set
 */
typedef void (^ZDSDKConfig) (ZDAccount*, ZDRequestCreationConfig*);


/**
 * Core SDK class providing access to request deflection, creation and lists.
 */
@interface ZDCoreSDK : NSObject {

    ZDRequestCreationConfig *requestCreationConfig;

}


/**
 * Request creation config for this instance.
 */
@property (strong) ZDRequestCreationConfig *requestCreationConfig;


/**
 * Get the instance of ZDCoreSDK
 * @return CoreSDK A shared instance of ZDCoreSDK
 */
+ (instancetype) instance;


/**
 * Configure the SDK
 * @param config the config block with which to setup the SDK.
 */
+ (void) configure:(ZDSDKConfig)config;


/**
 * Displays a simple request creation modal. The modal is presented on top the view controller
 * that is passed in.
 *
 * @param viewController The view controller from which to pressent the request creation view.
 * @param success A block that is executed on successfull submission of a request.
 * @param error A block that is executed when an error occurs during submission of a request.
 */
+ (void) showRequestCreationWithNavController:(UINavigationController*)nc
                                withSuccess:(ZDAPISuccess)success
                                   andError:(ZDAPIError)error;


/**
 * Create a new request list component for use, initially the component will have a CGRectZero frame.
 *
 * @param observer event observer for receiving notification of table updates
 * @param selector the selector to be invoked on table update events
 * @return a new request list component
 */
+ (ZDRequestListTable*) newRequestListWith:(id)observer andSelector:(SEL)selector;


#pragma mark - inactive


//+ (void) showRequestDeflectionInViewController:(UIViewController*)viewController withOptions:(NSObject*)todo;



@end
