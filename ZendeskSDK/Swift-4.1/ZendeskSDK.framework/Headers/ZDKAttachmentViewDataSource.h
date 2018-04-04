/*
 *
 *  ZDKAttachmentViewDataSource.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 02/02/2015.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>


/**
 *  Collection view data source for ZDKAttachmentView.
 */
@interface ZDKAttachmentViewDataSource : NSObject <UICollectionViewDataSource>


@property (nonatomic, copy) NSMutableArray *data;

@end
