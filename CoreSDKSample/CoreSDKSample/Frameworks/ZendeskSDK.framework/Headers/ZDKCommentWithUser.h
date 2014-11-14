//
//  ZDKCommentWithUser.h
//  ZendeskSDK
//
//  Created by Zendesk on 10/11/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>
@class ZDKComment, ZDKUser;

@interface ZDKCommentWithUser : NSObject

@property (nonatomic, readonly) ZDKComment *comment;
@property (nonatomic, readonly) ZDKUser *user;

+ (instancetype) buildCommentWithUser:(ZDKComment *)comment withUsers:(NSArray *)users;

@end
