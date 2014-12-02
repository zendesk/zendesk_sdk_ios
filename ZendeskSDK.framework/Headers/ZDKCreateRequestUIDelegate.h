/*
 *
 *  ZDKCreateRequestUIDelegate.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 12/11/2014.  
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
 *  Enum to describe the types of nav bar button that display request creation.
 */
typedef NS_ENUM(NSUInteger, ZDKNavBarCreateRequestUIType) {
    /**
     *  Nav bar button with localized label for request creation.
     */
    ZDKNavBarCreateRequestUITypeLocalizedLabel,
    /**
     *  Nav bar button with image for request creation.
     */
    ZDKNavBarCreateRequestUITypeImage,
};


@protocol ZDKCreateRequestUIDelegate <NSObject>


/**
 *  To conform implementations should return the request creation UI type desired.
 *
 *  @return The ZDKNavBarCreateRequestUIType to display.
 */
- (ZDKNavBarCreateRequestUIType) navBarCreateRequestUIType;


/**
 *  To conform implementations should return an immage for the right nav bar button.
 *
 *  @return An image for the right nav bar button.
 */
- (UIImage *) createRequestBarButtonImage;

/**
 *  To conform implementations should return a localized string for the right nav bar button title.
 *
 *  @return A localized string for the right nav bar button.
 */
- (NSString *) createRequestBarButtonLocalizedLabel;

@end
