//
//  ZDToastStyle.h
//  ZDToast
//
//  Created by Zendesk on 13/05/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>


/**
 * Toast types providing specific styling as defined in ZDToastStyle.
 * @since 0.1
 */
typedef enum _ZDToastType {
    ZDToastInfo,
    ZDToastOK,
    ZDToastWarning,
    ZDToastError,
    ZDToastType_count
} ZDToastTypeEnum;


/**
 * Toast styling options.
 * @since 0.1
 */
typedef enum _ZDToastStyle {
    ZDToastStyleBackgroundColor,
    ZDToastStyleBorderColor,
    ZDToastStyleFontColor,
    ZDToastStyleFontName,
    ZDToastStyleFontSize,
    ZDToastStyleIconName, // v0.2
    ZDToastStyle_count
} ZDToastStyleEnum;


/**
 * Singleton class holding the styling details for toast messages.
 * @since 0.1
 */
@interface ZDToastStyle : NSObject


/**
 * Set the style value for the specified type.
 * @param value this should be: UIColor for 'Color' styles, NSString for 'Name' styles and NSNumber for 'Size' styles
 * @param type ZDToastTypeEnum defining the type to be styled
 * @param style ZDToastStyleEnum defining the style to be set
* @since 0.1
 */
+ (void) setValue:(id)value forType:(ZDToastTypeEnum)type andStyle:(ZDToastStyleEnum)style;


/**
 * Get the requested style value for the type.
 * @param type ZDToastTypeEnum defining the style to be retrieved
 * @param style ZDToastStyleEnum the style to be retrieved
 * @since 0.1
 */
+ (id) getValueForType:(ZDToastTypeEnum)type andStyle:(ZDToastStyleEnum)style;


@end

