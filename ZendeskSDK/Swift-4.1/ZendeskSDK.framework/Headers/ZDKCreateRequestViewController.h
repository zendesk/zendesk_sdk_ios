/*
 *
 *  ZDKCreateRequestViewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on  22/12/2015
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
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


/**
 *  Dismisses the create request screen.
 *
 *  @since 1.7.2.1
 */
- (void)dismiss;

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

@end
