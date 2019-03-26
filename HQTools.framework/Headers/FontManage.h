//
//  FontManage.h
//  IMChatNew
//
//  Created by mac-a on 2016/12/26.
//  Copyright © 2016年 mac-a. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    FONT_MIN = 1,//最小號字體
    FONT_STANDARD = 2,//标准字体
    FONT_MAX = 3,//大号字體
    FONT_VERY_MAX = 4, //大號字體
} FONT_SIZE;

#define FontManagerParam 0.2
@interface FontManage : NSObject

+(CGFloat)currentHeightScal;
//獲取適配完成後的字體
+(UIFont *)systemFontSizeNumber:(CGFloat)number;
//默認的字體
+(UIFont *)systemFontSize;
//加粗完成後的字體
+(UIFont *)boldSystemFontOfSize:(CGFloat)number;
//當前字體的大小
+(CGFloat)currentFontNumber;
//當前字體的標註
+(FONT_SIZE)getCurrentFontSize;
//設置當前字體的標識
+(void)setCurrentFontSize:(FONT_SIZE)font;
//根據傳過來的值返回適配完成後的大小
+(CGFloat)currentSizeForNumber:(CGFloat)number;
//获取当前字体改变后的屏幕上宽度
+(CGFloat)currentFontWithScale:(CGFloat)number;
//當前放大比例
+(CGFloat)currentFontScal;

//19号
+(UIFont *)navTitleFont;
//15
+(UIFont *)nameTitleFont;
//13
+(UIFont *)subTitleFont;
//15
+(UIFont *)cellTitleFont;
//12
+(UIFont *)tabbarItemFont;
//11
+(UIFont *)unreadPageFont;
//12
+(UIFont *)TWChatCellTitleFont;
//14
+(UIFont *)TWChatCellVoiceFont;
//text 14
+(UIFont *)TWChatCellTextFont;
+(NSInteger)TWChatCellTextFontNum;
+(NSInteger)TWChatCellTalkingTextFontNum;
+(NSInteger)TWTextFontNum:(NSInteger)fontNum;
+(CGFloat)fontManagerAutoFontnum:(CGFloat)num;
//10
+(UIFont *)TWLogin10;
//12
+(UIFont *)TWLogin12;
//13
+(UIFont *)TWLogin13;
//14
+(UIFont *)TWLogin14;
//15
+(UIFont *)TWLogin15;
//16
+(UIFont *)TWLogin16;
//17
+(UIFont *)TWLogin17;
//19
+(UIFont *)TWLogin19;
//20
+(UIFont *)TWLogin20;
//21
+(UIFont *)TWLogin21;
//22
+(UIFont *)TWLogin22;
//24
+(UIFont *)TWLogin24;
//36
+(UIFont *)TWLogin36;
//
+(UIFont *)TWRightNorBtnFont;

+(UIColor *)navTitleColor;
+(UIColor *)nameTitleColor;
+(UIColor *)subTitleColor;
+(UIColor *)cellTitleColor;
+(UIColor *)tabbarItemNorColor;
+(UIColor *)sectionContentColor;
+(UIColor *)timeColor;

+(UIColor *)cellSepColor;
+(UIColor *)sectionRightSeqColor;
+(UIColor *)switchOFFColor;
+(UIColor *)selectPeopleColor;
//主色调
+(UIColor *)themeMain3Coclor;
+(UIColor *)phoneContentCoclor:(NSInteger)personId;

+(NSString *)friendCircleLinkColor;
+(NSString *)friendCircleConmentColor;
@end
