/*
 *
 *  ZDKCommentInputView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 06/02/2015.
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


@protocol ZDKCommentInputViewDelegate <NSObject>

@optional

/**
 *  Called to determine whether the send action is executed.
 *  Defaults to yes if not implemented.
 *
 *  @return YES to execute the send action. Return NO to block execution the send action.
 */
- (BOOL) shouldSelectSend;


/**
 *  Called when the send button is pressed.
 *
 *  @param commentBody the comment text.
 */
- (void) didSelectSend:(NSString *)commentBody;


/**
 *  Called to determine whether the attachment action is executed. 
 *  Defaults to yes if not implemented.
 *
 *  @return YES to execute the attachment action. Return NO to block execution the attachment action.
 */
- (BOOL) shouldSelectAttachment;


/**
 *  Called when the attachment button is selected.
 */
- (void) didSelectAttachment;


@end


@class ZDKUITextView;


@interface ZDKCommentInputView : UIView


/**
 *  Create a Comment Input View
 *
 *  @param attachmentEnabled is attachement enabled
 */
- (instancetype)initWithAttachemntEnabled:(BOOL)attachmentEnabled;


@property (nonatomic, strong, readonly) ZDKUITextView *textView;


@property (nonatomic, strong, readonly) UIButton *sendButton;

/**
 *  Returns the preferred height for the input view.
 *
 *  @return the preferred height. 
 */
- (CGFloat) preferredHeight;


@end
