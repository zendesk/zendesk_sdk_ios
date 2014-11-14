//
//  ZDKUITextViewDelegate.h
//  ZendeskSDK
//
//  Created by Zendesk on 09/05/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ZDKUITextViewDelegate <UITextViewDelegate>

- (void) caretPosition:(CGRect)caret;

@end
