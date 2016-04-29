/*
 *
 *  ZDKCommentInputView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 06/02/2015.
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


@property (nonatomic, readonly) ZDKUITextView *textView;


@property (nonatomic, readonly) UIButton *sendButton;

/**
 *  Delegate for ZDKCommentInputView.
 */
@property (nonatomic, assign) id<ZDKCommentInputViewDelegate> delegate;


/**
 * Color of border line at top of text entry area.
 */
@property (nonatomic, strong) UIColor *topBorderColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


/**
 * Font for the text entry view and it's placeholder.
 */
@property (nonatomic, strong) UIFont *textEntryFont __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


/**
 * Color of the text entry text.
 */
@property (nonatomic, strong) UIColor *textEntryColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;

/**
 *  Color of the placeholder text.
 */
@property (nonatomic, strong) UIColor *textEntryPlaceHolderColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


/**
 * Text entry box background color.
 */
@property (nonatomic, strong) UIColor *textEntryBackgroundColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


/**
 * Text entry box border color.
 */
@property (nonatomic, strong) UIColor *textEntryBorderColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


/**
 * Send button font.
 */
@property (nonatomic, strong) UIFont *sendButtonFont __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


/**
 * Send button text color.
 */
@property (nonatomic, strong) UIColor *sendButtonColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


/**
 * Comment entry area background color.
 */
@property (nonatomic, strong) UIColor *areaBackgroundColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


/**
 *  Background color of attachment button.
 */
@property (nonatomic, strong) UIColor *attachmentButtonBackgroundColor __deprecated_msg("As of version 1.6.0.1, please use ZDKTheme for UI customization") UI_APPEARANCE_SELECTOR;


/**
 *  Returns the preferred height for the input view.
 *
 *  @return the preferred height. 
 */
- (CGFloat) preferredHeight;


@end
