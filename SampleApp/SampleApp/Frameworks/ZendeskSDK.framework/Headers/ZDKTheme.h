/*
 *
 *  ZDKTheme.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 20/04/2016.
 *
 *  Copyright (c) 2016 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface ZDKTheme : NSObject

/**
 *  Primary text color
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, strong) UIColor *primaryTextColor;

/**
 *  Secondary text Color
 *
 *  @since 1.7.0.1
 */
@property (nonatomic, strong) UIColor *secondaryTextColor;

/**
 *  Primary background color.
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, strong) UIColor *primaryBackgroundColor;

/**
 *  Secondary background color, used when a slight contrast is needed against the primary background color, such as an end user comment cell.
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, strong) UIColor *secondaryBackgroundColor;

/**
 *  Empty background color, used when a view is has no content
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, strong) UIColor *emptyBackgroundColor;

/**
 *  Color of any metadata, such as dates or placeholder text
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, strong) UIColor *metaTextColor;

/**
 *  Cell seperator color
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, strong) UIColor *separatorColor;

/**
 *  Color of text for user input in ZDKCreateRequest and ZDKCommentInputView
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, strong) UIColor *inputFieldTextColor;

/**
 *  Background color of ZDKCommentInputView
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, strong) UIColor *inputFieldBackgroundColor;

/**
 *  Font to use in the SDK. This must be a complete font name, not a font family name.
 *
 *  @since 1.6.0.1
 */
@property (nonatomic, copy) NSString *fontName;

/**
 *  Bold font to use in the SDK.
 *
 *  @since 1.7.0.1
 */
@property (nonatomic, copy) NSString *boldFontName;

/**
 *  Apply the theme to the SDK
 *
 *  @since 1.6.0.1
 */
- (void)apply;

/**
 *  Returns a newly created instance filled with values from the Base SDK UI starndard theme.
 *
 *  Theme properties will be set to the standard theme.
 *
 *  @since 1.6.0.1
 */
+ (instancetype)baseTheme;

/**
 *  Get the current theme used in the SDK
 *
 *  @since 1.6.0.1
 */
+ (instancetype)currentAppliedTheme;


/**
 *  Use +[ZDKTheme baseTheme] instead to return a theme that you can edit
 *
 *  @since 1.6.0.1
 */
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
