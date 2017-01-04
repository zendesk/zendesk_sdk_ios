/*
 *
 *  ZDKCoreCreateRequestView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 31/10/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>
#import "ZDKSpinnerDelegate.h"

@class ZDKUITextView;


/**
 * Request creation view.
 *
 *  @since 0.9.3.1
 */
@interface ZDKCreateRequestView : UIView <UIAppearanceContainer>

/**
 * Text view for request description.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, strong) ZDKUITextView *textView;

/**
 * Text field for email input. Only shown if using anonymous and conversations disabled.
 *
 *  @since 1.4.0.1
 */
@property (nonatomic, strong) UITextField *emailField;

/**
 *  Button to allow user to attach images
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, strong) UIButton *attachImageButton;

/**
 *  Height of the textView frame
 *
 *  @since 1.1.0.1
 */
@property (nonatomic, readonly, assign) NSInteger textViewHeight;


@end
