//
//  ZDKModelObject.h
//  ZendeskSDK
//
//  Created by Zendesk on 13/06/2014.
//  Copyright (c) 2014 Zendesk. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "ZDKAccount.h"
#import "ZDKDispatcher.h"
#import "ZendeskSDKConstants.h"


/**
 * Base model class providing convenience methods for all model objects.
 */
@interface ZDKModelObject : NSObject


/**
 * The account object with the details necessary to form requests
 */
@property (nonatomic, strong) ZDKAccount *account;


/*
 * The dispatcher to be used for sending requests
 */
@property (nonatomic, strong) ZDKDispatcher *dispatcher;


/**
 * Initialise the model object with the account details ands the dispatcher to be used for requests.
 *
 * @param theAccount the account object with the details necessary to form requests
 * @param theDispatcher the dispatcher to be used for sending requests
 * @return the user cache, may be nil if not required
 */
- (instancetype) initWithAccount:(ZDKAccount*)theAccount dispatcher:(ZDKDispatcher*)theDispatcher;


#pragma mark persistence


/**
 * Override and implement to use persistence.
 *
 * @param dict NSDictionary of data that was persisted
 */
- (void) parseStoredData:(NSDictionary*)dict;


/**
 * Override and implement to use persistence.
 *
 @return NSDictionary of data to be persisted
 */
- (NSDictionary*) dataToPersist;


#pragma mark json helpers


/**
 * nil checked method for adding a value to a dictionary, if the value is nil then nothing will be done.
 *
 * @param value the value to set
 * @param key the key of the object to be set
 * @param dict the dictionary in which to set the object
 */
+ (void) setObject:(id)value withKey:(NSString*)key inDictionary:(NSMutableDictionary*)dict;


/**
 * Checks the return value for NSNull and converts to nil if found.
 *
 * @param json the JSON dictionary from which to get the value
 * @param key the key of the object to be retrieved
 * @return the value if found and not NSNull, otherwise nil
 */
+ (id) cleanJSONVal:(NSDictionary*)json key:(NSString*)key;


/**
 * Check the value for NSNull.
 *
 * @param val the value to be checked
 * @return the value if not NSNull, otherwise nil
 */
+ (id) cleanJSONVal:(id)val;


/**
 * Get the NSDate object from an API date string (e.g. 2014-05-22T12:58:30Z).
 *
 * @param string the date string from the API
 * @return the NSDate representation of the string
 */
+ (NSDate*) dateForJsonString:(NSString*)string;


#pragma mark date conversions


/**
 * Convert the date to an NSNumber of the timeIntervalSince1970.
 *
 * @param date the date to be converted
 * @return the NSNumber of the timeIntervalSince1970
 */
+ (NSNumber*) dateAsNumber:(NSDate*)date;


/**
 * Convert the timeIntervalSince1970 into an NSDate object.
 *
 * @param date the NSNumber of the timeIntervalSince1970
 * @return the NDDate representation of that number
 */
+ (NSDate*) dateFromNumber:(NSNumber*)date;


/**
 * Obtain the date from the provided string using the specified format.
 *
 * @param string the date string
 * @param format the format to be used to read the string
 * @return the date object if it can be parsed, otherwise nil
 */
+ (NSDate*) dateFromString:(NSString*)string usingFormat:(NSString*)format;


/**
 * Generate a string from the date using the specified format.
 *
 * @param date the date to be used
 * @param format the format to be used to create the string
 * @return the string if it can be created, otherwise nil
 */
+ (NSString*) stringFromDate:(NSDate*)date usingFormat:(NSString*)format;


/**
 * Get a cached thread local formatter for the requested date format.
 *
 * @return the formatter
 */
+ (NSDateFormatter*) formatterForFormat:(NSString*) format;


@end
