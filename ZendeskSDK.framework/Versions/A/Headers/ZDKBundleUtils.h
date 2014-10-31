//
//  ZDKBundleUtils.h
//  ZendeskSDK
//
//  Created by Zesnesk on 22/10/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface ZDKBundleUtils : NSObject


/**
 * Gets the framework resource bundle.
 *
 * @return The frameworks resource NSBundle or nil if the SDK bundle was not found.
 */
+ (NSBundle *) frameworkResourceBundle;


/**
 * Gets the framework strings bundle.
 *
 * @return The frameworks strings NSBundle or nil if the SDK bundle was not found.
 */
+ (NSBundle *) frameworkStringsBundle;


/**
 * Get the path for a resource in the SDK bundle.
 *
 * @param name The resource name.
 * @param extension The file extension.
 * @return The path for the css file, or nil if file was not found.
 */
+ (NSString *) pathForFrameworkResource:(NSString *)name ofType:(NSString *)extension;


/**
 * Get the help center css file in the SDK bundle and return as a string.
 *
 * @return A string containing css for help center.
 */
+ (NSString *) helpCenterCss;


/**
 * Get the help center css file in the host apps main bundle and return as a string.
 *
 * If you want your own style sheet for help center include a file named
 * help_center_article_style.css in your project and ensure it's included in the
 * Copy Bundle Resources build phase.
 *
 * @return A string containing css for help center.
 */
+ (NSString *) userDefinedHelpCenterCss;


/**
 *  The name of the frameworks strings table
 *
 *  @return The string table name.
 */
+ (NSString *) stringsTableName;


@end
