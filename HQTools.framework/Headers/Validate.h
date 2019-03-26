//
//  DefineHeader.h
//  ivy
//
//  Created by Herman on 2018/7/9.
//  Copyright © 2018年 WangMangui. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface Validate : NSObject

+(NSString *)printstringAndRerurn:(NSString *)str;
//验证身份证号
+ (BOOL) validateIdentityCard: (NSString *)identityCard;

//验证手机
+ (BOOL)validateTelNumber:(NSString*)telNumber;

+ (BOOL) validateEmail:(NSString *)email;

//验证昵称
+ (BOOL) validateNickname:(NSString *)nickname;

//验证密码
+ (BOOL) validatePassword:(NSString *)passWord;

//倒计时按钮
- (void)sendCodeSuccess:(UIButton *)btn ;


//MD5加密 32位小写
+ (NSString *)md5:(NSString *)content;


//获取视频第一帧图片
+(UIImage *)getImage:(NSString *)videoURL;

////获取用户id
//+ (NSString *)query;
//+ (NSString *)queryToken;


//判断是否是当天
+(NSString *)getDate:(NSString *)date;

//诺数大于10000转换
+ (NSString *)getBrowse:(NSString *)browse;

//时间戳转为字符串
+ (NSString *)changeTime:(NSNumber* )time;
+ (NSString *)transformTimeIntervalToCurrentTime:(NSString *)interval;

+ (NSString *)checkEmpty:(NSString *)str;

+ (BOOL )checkEmptyWithArray:(NSArray *)array;
+ (BOOL )checkEmptyWithDict:(NSDictionary *)dict;
//获取现在时间
+ (NSString * )getNowDate;

+ (NSString *)getAfterDate:(NSInteger )day;
/**
 *  转化时间 时间戳转时间
 */
+ (NSString *)datestrFromDate:(NSDate *)date
               withDateFormat:(NSString *)format;


//字典转json字符串
+ (NSString *)stringConvertToJsonString:(NSDictionary *)dict;
//json字符串转字典
+ (NSDictionary *)jsonStringConvertToDict:(NSString *)string;
//判断文件是否存在
+(BOOL) isFileExist:(NSString *)fileName;

+(UIColor *)getLevelCorlrWithLevel:(NSUInteger)level;
@end
