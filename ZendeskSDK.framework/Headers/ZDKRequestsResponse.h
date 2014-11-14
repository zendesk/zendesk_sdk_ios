//
//  ZDKRequestsResponse.h
//  ZendeskSDK
//
//  Created by Zendesk on 10/11/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZDKRequestsResponse : NSObject

+ (NSArray *) parseRequestListWithDictionary:(NSDictionary*)dictionary;

@end
