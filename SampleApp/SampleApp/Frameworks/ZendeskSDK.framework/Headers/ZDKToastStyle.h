/*
 *
 *  ZDKToastStyle.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 13/05/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */


#import <Foundation/Foundation.h>


/**
 * Toast types providing specific styling as defined in ZDKToastStyle.
 * @since 0.1
 */
typedef NS_ENUM(NSUInteger, ZDKToastUIType) {
    ZDKToastUITypeInfo,
    ZDKToastUITypeOK,
    ZDKToastUITypeWarning,
    ZDKToastUITypeError,
    ZDKToastUIType_count
};




/**
 * Toast styling options.
 * @since 0.1
 */
typedef NS_ENUM(NSUInteger, ZDKToastUIStyle) {
    ZDKToastUIStyleBackgroundColor,
    ZDKToastUIStyleBorderColor,
    ZDKToastUIStyleFontColor,
    ZDKToastUIStyleButtonBorderColor,
    ZDKToastUIStyleButtonBackgroundColor,
    ZDKToastUIStyleButtonFontColor,
    ZDKToastUIStyleButtonFontName,
    ZDKToastUIStyleButtonFontSize,
    ZDKToastUIStyleFontName,
    ZDKToastUIStyleFontSize,
    ZDKToastUIStyleIconName, // v0.2
    ZDKToastUIStyle_count
};



/**
 * Singleton class holding the styling details for toast messages.
 * @since 0.1
 */
@interface ZDKToastStyle : NSObject


/**
 * Set the style value for the specified type.
 * @param value this should be: UIColor for 'Color' styles, NSString for 'Name' styles and NSNumber for 'Size' styles
 * @param type ZDKToastUIType defining the type to be styled
 * @param style ZDKToastUIStyle defining the style to be set
 * @since 0.1
 */
+ (void) setValue:(id)value forType:(ZDKToastUIType)type andStyle:(ZDKToastUIStyle)style;



/**
 * Get the requested style value for the type.
 * @param type ZDKToastUIType defining the style to be retrieved
 * @param style ZDKToastUIStyle the style to be retrieved
 * @since 0.1
 */
+ (id) getValueForType:(ZDKToastUIType)type andStyle:(ZDKToastUIStyle)style;


@end

