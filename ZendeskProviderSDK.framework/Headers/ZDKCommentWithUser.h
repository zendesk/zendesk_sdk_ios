/*
 *
 *  ZDKCommentWithUser.h
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
@class ZDKComment, ZDKUser;

/**
 *  Aggregate model for comments with users.
 *
 *  @since 0.9.3.1
 */
@interface ZDKCommentWithUser : NSObject

/**
 *  The comment model.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, readonly) ZDKComment *comment;

/**
 *  The user associated with the comment model.
 *
 *  @since 0.9.3.1
 */
@property (nonatomic, readonly) ZDKUser *user;

/**
 *  Build an instance with comment and a user.
 *
 *  @since 0.9.3.1
 *
 *  @param comment A comment to build with.
 *  @param users   A user to associate to a comment.
 *
 *  @return A new instance.
 */
+ (instancetype) buildCommentWithUser:(ZDKComment *)comment withUsers:(NSArray *)users;

@end
