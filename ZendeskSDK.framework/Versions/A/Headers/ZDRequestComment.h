//
//  ZDRequestComment.h
//  ZDAPI
//
//  Created by Zendesk on 13/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import "ZDModelObject.h"


/**
 * A comment on a Zendesk request.
 */
@interface ZDRequestComment : ZDModelObject

/**
 * The id of this comment in Zendesk.
 */
@property (nonatomic, strong) NSNumber *commentId;

/**
 * The comment body/text.
 */
@property (nonatomic, strong) NSString *body;

/**
 * The Zendesk user id of the author.
 */
@property (nonatomic, strong) NSNumber *authorId;

/**
 * The list of attachments for this comment.
 */
@property (nonatomic, strong) NSArray *attachments;

/**
 * The timestmp fpr the creation of this comment.
 */
@property (nonatomic, strong) NSDate *createdAt;


/**
 * Initialise the model object with the account details ands the dispatcher to be used for requests.
 *
 * @param account the account object with the details necessary to form requests
 * @param dispatcher the dispatcher to be used for sending requests
 * @param dict the dictionary generated from the API json
 */
- (instancetype) initWithAccount:(ZDAccount *)account
                      dispatcher:(ZDDispatcher *)dispatcher
                         andDict:(NSDictionary*)dict;


@end

