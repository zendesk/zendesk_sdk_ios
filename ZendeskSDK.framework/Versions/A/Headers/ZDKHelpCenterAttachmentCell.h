//
//  ZDKHelpCenterAttachmentCell.h
//  ZendeskSDK
//
//  Created by Zendesk on 30/09/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ZDKHelpCenterAttachmentCell : UITableViewCell


/**
 * A label which displays the articles parent category and section.
 *
 */
@property (nonatomic, strong) UILabel *fileSize;


/**
 * Helper method to retrieve this classes cell identifier.
 *
 * @returns The classes cell identifier.
 */
+ (NSString *) cellIdentifier;


+ (NSString *) humanReadableFileSize:(NSUInteger) bytes;

@end
