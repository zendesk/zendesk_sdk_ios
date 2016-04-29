/*
 *
 *  ZDKCreateRequestViewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on  22/12/2015
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>
#import <MobileCoreServices/MobileCoreServices.h>


typedef void (^ZDKCreateRequestSuccess) (id result);
typedef void (^ZDKCreateRequestError) (NSError *error);

@class ZDKReachabilityWrapper, ZDKToastViewWrapper, ZDKCreateRequestViewController, ZDKUITextView;

/**
 *  Request creation view controller delegate methods.
 *
 *  @since 1.6.0.1
 */
@protocol ZDKCreateRequestViewControllerDelegate <NSObject>

@optional

/**
 *  Delegate method called when the create request view controller finishes
 *
 *  @since 1.6.0.1
 *
 *  @param viewController the create request view controller
 */
- (void)createRequestViewControllerDidFinish:(ZDKCreateRequestViewController*)viewController;

/**
 *  Delegate method called when a ticket is created successfully
 *
 *  @since 1.6.0.1
 *
 *  @param viewController the create request view controller
 *  @param result the created ticket
 */

- (void)createRequestViewController:(ZDKCreateRequestViewController*)viewController didCreateTicketWithSuccess:(id)result;

/**
 *  Delegate method called when a ticket creation fails
 *
 *  @since 1.6.0.1
 *
 *  @param viewController the create request view controller
 *  @param error the error
 */

- (void)createRequestViewController:(ZDKCreateRequestViewController*)viewController didFailCreateTicketWithError:(NSError*)error;

@end


/**
 *  Request creation view controller.
 *
 *  @since 0.9.3.1
 */
@interface ZDKCreateRequestViewController : UIViewController


/**
 *  Create request view controller delegate
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, weak) id<ZDKCreateRequestViewControllerDelegate> delegate;

/**
 *  Init with provided success and error blocks.
 *
 *  @since 0.9.3.1
 *
 *  @param success the success
 *  @param error the request object this comment is for
 *  @return the instance
 */
- (instancetype) initWithSuccess:(ZDKCreateRequestSuccess)success
                        andError:(ZDKCreateRequestError)error __deprecated_msg("As of version 1.6.0.1 use -init instead, for callbacks use ZDKCreateRequestViewControllerDelegate");


@end
