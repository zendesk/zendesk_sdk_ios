/*
 *
 *  ZDKCommentsViewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 04/02/2015.
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

#import "ZDKUIViewController.h"

@class ZDKRequest;


@interface ZDKCommentsViewController : ZDKUIViewController


/**
 *  The orignional request for the comment stream.
 */
@property (nonatomic, readonly) ZDKRequest *request;


/**
 *  Initialize the comments controller with a request.
 *
 *  @param aRequest A request model.
 *
 *  @return A new instance of ZDKCommentsViewController.
 */
- (instancetype) initWithRequest:(ZDKRequest *)aRequest;


/**
 *  Dismiss the controller that was presented modally.
 */
- (void) dismiss;


@end
