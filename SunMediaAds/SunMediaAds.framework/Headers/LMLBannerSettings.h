//
//  LMLBannerSettings.h
//  LabCaveMediationLib
//
//  Created by LabCaveGames on 23/04/2019.
//  Copyright © 2019 Lab Cave Apps S.L. All rights reserved.
//

#import <Foundation/Foundation.h>
#define LMLBannerSettings_BANNER_TOP [[LMLBannerSettings alloc] initWithSize:@"BANNER_TOP"]
#define LMLBannerSettings_BANNER_BOTTOM [[LMLBannerSettings alloc] initWithSize:@"BANNER_BOTTOM"]
#define LMLBannerSettings_SMART_TOP [[LMLBannerSettings alloc] initWithSize:@"SMART_TOP"]
#define LMLBannerSettings_SMART_BOTTOM [[LMLBannerSettings alloc] initWithSize:@"SMART_BOTTOM"]
/**
 *  Banner Size
 */
typedef NS_ENUM(NSUInteger, LMLSize) {
    /**
     *  SmartBanner device_widthx50|90
     */
    LMLSmartBanner,
    /**
     *  Banner 320x50 | 720x90
     */
    LMLBanner
};
/**
 *  Banner position
 */
typedef NS_ENUM(NSUInteger, LMLPosition) {
    /**
     *  Bottom screen position
     */
    LMLBottom,
    /**
     *  Top screen position
     */
    LMLTop
};
@interface LMLBannerSettings : NSObject
- (instancetype)initWithSize:(NSString *)size;
- (void)setSize:(LMLSize)size;
- (void)setPosition:(LMLPosition)position;
@property (readonly) LMLPosition position;
@property (readonly) LMLSize size;
@end
