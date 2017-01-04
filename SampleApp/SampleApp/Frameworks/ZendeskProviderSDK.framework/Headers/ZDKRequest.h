/*
 *
 *  ZDKRequest.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 13/06/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */


/**
 * Object representing a Zendesk end user request returned by the server.
 */
@interface ZDKRequest : NSObject

/**
 * The id of this request in Zendesk.
 */
@property (nonatomic, copy) NSString *requestId;

/**
 * The id of the requester in Zendesk.
 */
@property (nonatomic, strong) NSNumber *requesterId;

/**
 * Request status.
 */
@property (nonatomic, copy) NSString *status;

/**
 * The subject of the request, if subject is enabled in the account and if a subject was entered.
 */
@property (nonatomic, copy) NSString *subject;

/**
 * The original request.
 */
@property (nonatomic, copy) NSString *requestDescription;

/**
 *  The request type
 */
@property (nonatomic, copy) NSString *type;

/**
 * The timestamp of the request creation.
 */
@property (nonatomic, strong) NSDate *createdAt;

/**
 * The timestamp of the last update event.
 */
@property (nonatomic, strong) NSDate *updateAt;

/**
 * The timestamp of the last public update event.
 */
@property (nonatomic, strong) NSDate *publicUpdatedAt;

/**
 *  The number of comments on this ticket.
 *
 *  @since 1.4.1.1
 */
@property (nonatomic, strong) NSNumber *commentCount;


/**
 * Init with dictionary from API response.
 *
 * @param dict the dictionary generated from the JSON API response
 */
- (instancetype) initWithDict:(NSDictionary*)dict;


@end

