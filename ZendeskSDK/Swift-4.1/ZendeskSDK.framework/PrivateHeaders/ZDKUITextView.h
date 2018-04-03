/*
 *
 *  ZDKUITextView.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 28/04/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */


#import <Foundation/Foundation.h>
#import "ZDKUITextViewDelegate.h"


/**
 * A UITextView with a placeholder that is shown when there is no text in the text
 * view. Retains all the functionality of a normal UITextView. Setting the font
 * on the text view sets the font on the placeholder. The placeholder text color
 * is set with the placeholderTextColor property.
 */
@interface ZDKUITextView : UITextView


/**
 * The placeholder text that is shown when there is no text in the text view.
 */
@property (nonatomic, strong) IBInspectable NSString *placeholderText;


/**
 * The color of the placeholder that is shown when there is no text in the text view.
 */
@property (nonatomic, strong) IBInspectable UIColor *placeholderTextColor;


/**
 * Init method for ZDKRMATextView.
 *
 * @param frame The frame for the text view
 * @param placeholderText The text for the placeholder
 * @return An initialized ZDKRMATextView object or nil if the object couldn't be created.
 *
 */
- (instancetype) initWithFrame:(CGRect)frame andPlaceholder:(NSString*)placeholderText;


@end
