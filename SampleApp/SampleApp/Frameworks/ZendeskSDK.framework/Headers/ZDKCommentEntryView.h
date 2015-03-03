/*
 *
 *  ZDKCommentEntryView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 19/06/2014.  
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
#import "ZDKUITextView.h"
#import "ZDKAPIDispatcher.h"


#define ZD_COMMENT_ENTRY_MINIMUM_HEIGHT 43.0f
#define ZD_COMMENT_ENTRY_TOP_BORDER_COLOR [UIColor colorWithWhite:0.831f alpha:1.0f]
#define ZD_COMMENT_ENTRY_TEXTENTRY_FONT [UIFont systemFontOfSize:15]
#define ZD_COMMENT_ENTRY_TEXTENTRY_COLOR [UIColor colorWithWhite:0.4f alpha:1.0f]
#define ZD_COMMENT_ENTRY_TEXTENTRY_BACKGROUND_COLOR [UIColor colorWithWhite:0.945f alpha:1.0f]
#define ZD_COMMENT_ENTRY_TEXTENTRY_BORDER_COLOR [UIColor colorWithWhite:0.831f alpha:1.0f]
#define ZD_COMMENT_ENTRY_SEND_FONT [UIFont systemFontOfSize:12]
#define ZD_COMMENT_ENTRY_SEND_TEXT_COLOR [UIColor colorWithWhite:0.2627f alpha:1.0f]
#define ZD_COMMENT_ENTRY_BAKCGROUND_COLOR [UIColor whiteColor]


/**
 * Comment entry text view and send button.
 */
__deprecated_msg(" As of version 1.1.1.1");
@interface ZDKCommentEntryView : UIView


/**
 * The request object for this comment is for.
 */
@property (nonatomic, strong) ZDKRequest *request;

/**
 * The top border line of the component.
 */
@property (nonatomic, strong) UIView *topBorder;

/**
 * The rounded corner background to the text input field.
 */
@property (nonatomic, strong) UIView *textViewBackground;

/**
 * The text entry field.
 */
@property (nonatomic, strong) ZDKUITextView *textView;

/**
 * The send button.
 */
@property (nonatomic, strong) UIButton *sendButton;

/**
 * Flag to indicate if sending the comment is in progress.
 */
@property (nonatomic, assign) BOOL sending;

/**
 * Color of border line at top of text entry area.
 */
@property (nonatomic, strong) UIColor *topBorderColor UI_APPEARANCE_SELECTOR;

/**
 * Font for the text entry view and it's placeholder.
 */
@property (nonatomic, strong) UIFont *textEntryFont UI_APPEARANCE_SELECTOR;

/**
 * Color of the text entry text.
 */
@property (nonatomic, strong) UIColor *textEntryColor UI_APPEARANCE_SELECTOR;

/**
 * Text entry box background color.
 */
@property (nonatomic, strong) UIColor *textEntryBackgroundColor UI_APPEARANCE_SELECTOR;

/**
 * Text entry box border color.
 */
@property (nonatomic, strong) UIColor *textEntryBorderColor UI_APPEARANCE_SELECTOR;

/**
 * Send button font.
 */
@property (nonatomic, strong) UIFont *sendButtonFont UI_APPEARANCE_SELECTOR;

/**
 * Send button text color.
 */
@property (nonatomic, strong) UIColor *sendButtonColor UI_APPEARANCE_SELECTOR;

/**
 * Comment entry area background color.
 */
@property (nonatomic, strong) UIColor *areaBackgroundColor UI_APPEARANCE_SELECTOR;


/**
 * Init with provided frame and request.
 *
 * @param frame the frame in which to render the UI
 * @param request the request object this comment is for
 * @return the instance
 */
- (instancetype) initWithFrame:(CGRect)frame andRequest:(ZDKRequest*)request;


/**
 * Returns the height that would be necessary to render the complete text of 
 * the text entry view given the current width of the component.
 *
 * @return the preferred height of the component
 */
- (CGFloat) preferredHeight;


@end

