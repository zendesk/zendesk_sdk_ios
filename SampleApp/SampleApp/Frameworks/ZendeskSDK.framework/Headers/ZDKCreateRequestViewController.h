/*
 *
 *  ZDKCoreCreateRequestViewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 25/04/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */


#import <UIKit/UIKit.h>
#import "ZDKAPIDispatcher.h"
#import "ZDKUITextViewDelegate.h"
#import "ZDKUIViewController.h"

@class ZDKCreateRequestView;

/**
 * Request creation view controller.
 */
@interface ZDKCreateRequestViewController : ZDKUIViewController <ZDKUITextViewDelegate, UITextFieldDelegate>


/**
 * API success block, called after succesfull request creation.
 */
@property (nonatomic, copy) ZDKAPISuccess onSuccess;


/**
 * API error block, called after a request creation error.
 */
@property (nonatomic, copy) ZDKAPIError onError;


/**
 * The request creation view.
 */
@property (nonatomic, strong) ZDKCreateRequestView *createRequestView;


/**
 * Init with provided success and error blocks.
 *
 * @param success the success
 * @param error the request object this comment is for
 * @return the instance
 */
- (instancetype) initWithSuccess:(ZDKAPISuccess)success
                        andError:(ZDKAPIError)error;


@end

