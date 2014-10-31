//
//  ZDKCoreCreateRequestViewController.h
//  ZendeskSDK
//
//  Created by Zendesk on 25/04/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "ZDKAPI.h"
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

