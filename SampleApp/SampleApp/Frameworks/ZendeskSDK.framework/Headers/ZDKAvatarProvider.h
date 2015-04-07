/*
 *
 *  ZDKAvatarProvider.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 10/11/2014.  
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
 *  Block invoked to pass data back from API call
 *
 *  @since 0.9.3.1
 *
 *  @param avatar UIImage of the response from server, can be nil on error
 *  @param error  NSError returned on during error state, can be nil on success
 */
typedef void (^ZDKAvatarCallback)(UIImage *avatar, NSError *error);


/**
 *  Provider for images/avatars.
 *
 *  @since 0.9.3.1
 */
@interface ZDKAvatarProvider : NSObject

/**
 *  Get the image/avatar data for a given URL
 *
 *  @since 0.9.3.1
 *
 *  @param avatarUrl NSString url of the image to be fetched
 *  @param callback  block callback executed on error or success states
 */
- (void) getAvatarForUrl:(NSString *)avatarUrl withCallback:(ZDKAvatarCallback)callback;

@end
