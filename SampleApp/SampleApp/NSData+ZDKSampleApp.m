/*
 *
 *  NSData+ZDKSampleApp.m
 *  SampleApp
 *
 *  Created by Zendesk on 19/03/2015.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import "NSData+ZDKSampleApp.h"

@implementation NSData (ZDKSampleApp)

- (NSString *) deviceIdentifier {

    NSMutableString* identifier = [NSMutableString stringWithString:[self.description uppercaseString]];
    [identifier replaceOccurrencesOfString:@"<" withString:@"" options:0 range:NSMakeRange(0, identifier.length)];
    [identifier replaceOccurrencesOfString:@">" withString:@"" options:0 range:NSMakeRange(0, identifier.length)];
    [identifier replaceOccurrencesOfString:@" " withString:@"" options:0 range:NSMakeRange(0, identifier.length)];
    return identifier;
}

@end
