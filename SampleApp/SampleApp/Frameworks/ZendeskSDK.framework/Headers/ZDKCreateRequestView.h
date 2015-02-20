/*
 *
 *  ZDKCoreCreateRequestView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 31/10/2014.  
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
#import "ZDKSpinnerDelegate.h"

@class ZDKUITextView;


/**
 * Request creation view.
 */
@interface ZDKCreateRequestView : UIView <UIAppearanceContainer>


/**
 * Text view for request description.
 */
@property (nonatomic, strong) ZDKUITextView *textView;

/**
 *  Button to allow user to attach images
 */
@property (nonatomic, strong) UIButton *attachImageButton;

/**
 *  Action sheet to allow attachment selection from camera or camera roll
 */
@property (nonatomic, strong) UIActionSheet *attachmentSourceSelectSheet;

/**
 *  Action sheet to allow deltion of attachments.
 */
@property (nonatomic, strong) UIActionSheet *attachmentOptionsSelectSheet;

/**
 * Color for the text views placeholder text.
 */
@property (nonatomic, strong) UIColor *placeholderTextColor UI_APPEARANCE_SELECTOR;


/**
 * Color for the text entry text.
 */
@property (nonatomic, strong) UIColor *textEntryColor UI_APPEARANCE_SELECTOR;

/**
 * Color for the background color of the text view
 */
@property (nonatomic, strong) UIColor *textEntryBackgroundColor UI_APPEARANCE_SELECTOR;

/**
 * Background color for the view.
 */
@property (nonatomic, strong) UIColor *viewBackgroundColor UI_APPEARANCE_SELECTOR;


/**
 * Font for the text entry view.
 */
@property (nonatomic, strong) UIFont *textEntryFont UI_APPEARANCE_SELECTOR;


/**
 *  Attachment button image.
 */
@property (nonatomic, strong) UIImage *attachmentButtonImage UI_APPEARANCE_SELECTOR;

/**
 *  Attachment button border color.
 */
@property (nonatomic, strong) UIColor *attachmentButtonBorderColor UI_APPEARANCE_SELECTOR;

/**
 *  Attachment button corner radius.
 */
@property (nonatomic, assign) CGFloat attachmentButtonCornerRadius UI_APPEARANCE_SELECTOR;

/**
 *  Attachment button border width.
 */
@property (nonatomic, assign) CGFloat attachmentButtonBorderWidth UI_APPEARANCE_SELECTOR;

/**
 *  Attachment button background color
 */
@property (nonatomic, strong) UIColor *attachmentButtonBackground UI_APPEARANCE_SELECTOR;


/**
 *  Action sheet style
 */
@property (nonatomic, assign) UIActionSheetStyle attachmentActionSheetStyle UI_APPEARANCE_SELECTOR;



/**
 * Loading spinner for the request creation view.
 */
@property (nonatomic, strong) id<ZDKSpinnerDelegate> spinner UI_APPEARANCE_SELECTOR;


/**
 * Number either 0 == NO, anything else is YES
 */
@property (nonatomic, assign) NSInteger automaticallyHideNavBarOnLandscape  UI_APPEARANCE_SELECTOR;


/**
 *  Height of the textView frame
 */
@property (nonatomic, readonly, assign) NSInteger textViewHeight;

/**
 *  Initalize attachmentSourceSelectionSheet.
 */
- (void) initAttachmentSourceSheet;


@end
