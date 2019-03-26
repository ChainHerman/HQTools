//
//  DEFINE.h
//  DZFProject2
//
//  Created by 土耳其大骗子 on 15/9/14.
//  Copyright (c) 2015年 土耳其大骗子. All rights reserved.
//

#ifndef DZFProject2_DEFINE_h
#define DZFProject2_DEFINE_h

// 设备类型判断
#define IsiPhone   (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IsRetain   ([[UIScreen mainScreen] scale] >= 2.0)
#define ScreenMaxLength (MAX(kScreenW, kScreenH))
#define ScreenMinLength (MIN(kScreenW, kScreenH))


#define iphoneWidth_320 (kScreenW==320.0f)

#define iphone4x_3_5 (kScreenW==480.0f)

#define iphone5x_4_0 (kScreenW==568.0f)

#define iphone6_4_7 (kScreenW==667.0f)

#define iphone6Plus_5_5 (kScreenW==736.0f || kScreenH==414.0f)

#define ISIPHONE_PLUS_HEIGHTCONFIG (iphone6Plus_5_5?1.2:1)

#define ISIPHONE_SMALL_HEIGHTCONFIG (iphoneWidth_320?1:1.2)

#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

#define iPhoneX [[UIScreen mainScreen] bounds].size.width >= 812.0f && [[UIScreen mainScreen] bounds].size.height >= 375.0f && IS_IPHONE

#define iPhoneX [[UIScreen mainScreen] bounds].size.width >= 812.0f && [[UIScreen mainScreen] bounds].size.height >= 375.0f && IS_IPHONE

//判断iPHoneXr
#define SCREENSIZE_IS_XR ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) && !UI_IS_IPAD : NO)

#define UI_IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//判断iPHoneX、iPHoneXs
#define SCREENSIZE_IS_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !UI_IS_IPAD : NO)
#define SCREENSIZE_IS_XS ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !UI_IS_IPAD : NO)

//判断iPhoneXs Max
#define SCREENSIZE_IS_XS_MAX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) && !UI_IS_IPAD : NO)

//重写NSLog,Debug模式下打印日志和当前行数
//#if DEBUG
//#define NSLog(FORMAT, ...) fprintf(stderr,"\nfunc:%s line:%d content:%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
//#else
//#define NSLog(FORMAT, ...) nil
//#endif

//DEBUG  模式下打印日志,当前行 并弹出一个警告
#ifdef DEBUG
#   define ULog(fmt, ...)  { UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithFormat:@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]  delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil]; [alert show]; }
#else
#   define ULog(...)
#endif

/**
 *  masonry 避免造成循环引用
 */
#define LYWS(weakSelf)  __weak __typeof(&*self)weakSelf = self;
#define NameFontNum             16
/**
 *  ReactiveCocoa语法糖
 */
#define Weakify(name)           @weakify(name)
#define Strongify(name)         @strongify(name)
/**
 *  屏幕的宽和高
 */
#define StateBarHeight          [UIApplication sharedApplication].statusBarFrame.size.height
#define kScreenW                [UIScreen mainScreen].bounds.size.width
#define kScreenH                [UIScreen mainScreen].bounds.size.height
//横屏保持不变

#define kScale                  [UIScreen mainScreen].scale
#define kNavBHeight             (44 + StateBarHeight)
#define iPhoneX_bottomH         (iPhoneX?34:0)
#define iPhoneX_topH            (iPhoneX?23:0)

#define kStateBarNarmalHeight   (iPhoneX?24:0)
#define kNavBNarmalHeight       (44 + kStateBarNarmalHeight)

#define currentScale iphone5x_4_0 ? ([FontManage currentHeightScal] >= 1.2 ? self.scaleHeight(1) : 1.02) : 1.02
#define IsNormalStateBar        (StateBarHeight == 20 || (StateBarHeight == 44 && iPhoneX))

#define kTextInputMaxCount    1500

#define kLeftViewControllerScale 0.8
#define kLeftViewControllerWidth kScreenW * kLeftViewControllerScale

/** print 打印rect,size,point */
#define kLogPoint(point)    NSLog(@"%s = { x:%.4f, y:%.4f }", #point, point.x, point.y)
#define kLogSize(size)      NSLog(@"%s = { w:%.4f, h:%.4f }", #size, size.width, size.height)
#define kLogRect(rect)      NSLog(@"%s = { x:%.4f, y:%.4f, w:%.4f, h:%.4f }", #rect, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height)
/**
 *  the saving objects      存储对象
 *
 *  @param __VALUE__ V
 *  @param __KEY__   K
 *
 *  @return
 */
#define UserDefaultSetObjectForKey(__VALUE__,__KEY__) \
{\
[[NSUserDefaults standardUserDefaults] setObject:__VALUE__ forKey:__KEY__];\
[[NSUserDefaults standardUserDefaults] synchronize];\
}

#ifdef DEBUG

#define DLog( s, ... ) NSLog( @"< %@:(%d) > %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )

#else

#define DLog( s, ... ) NSLog(@"")

#endif

/**
 *  get the saved objects       获得存储的对象
 */
#define UserDefaultObjectForKey(__KEY__)  [[NSUserDefaults standardUserDefaults] objectForKey:__KEY__]

/**
 *  delete objects      删除对象
 */
#define UserDefaultRemoveObjectForKey(__KEY__) \
{\
[[NSUserDefaults standardUserDefaults] removeObjectForKey:__KEY__];\
[[NSUserDefaults standardUserDefaults] synchronize];\
}
/**
 *  获取主窗口
 */
#define KeyWindow   [UIApplication sharedApplication].keyWindow


/**
 *  字体设置
 */
#define FontS(number)           [FontManage systemFontSizeNumber:number]
#define FontB(number)           [FontManage boldSystemFontOfSize:number]
#define PANWIDTH 17
/**
 *  自定义颜色
 */
#define LYColor(r,g,b)          [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:1.0f]
#define LYColorA(r,g,b,a)       [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define UIColorFromRGB(rgbValue)    [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

/**
 *  导航条的统一设置
 */
#define NavBarTitleFont         [UIFont boldSystemFontOfSize:18]
#define NavBarTitleColor        LYColor(0,0,0)
#define NavBarItemFont          [UIFont boldSystemFontOfSize:16]
#define NavBarItemColor         LYColor(255,255,255)
#define NavBarItemHighColor     LYColorA(255,255,255,0.5)

#define NavBarCommColor         LYColor(25, 156, 163)
#define SearchBarTinColor       LYColor(0x99, 0x99, 0x99)

#define SearchBarBackgroundColor LYColor(0xf0, 0xf0, 0xf4)

/**
 *登录按钮统一颜色
 */

#define LoginInButtonColor      LYColor(54, 172, 178)
//线条同意颜色
#define SignColor               LYColor(232, 232, 232)

//textView提示文字默认颜色
#define PlaceHolderColor        LYColor(183,183,183);

#define DefineTime              30

#define NEEDCHANGFONT           [FontManage TWChatCellTextFont]

//指示器显示时间
#define SVPDurtion              2

#define DEFINESELECTPEOP        self.scaleHeight(52)
#define DEFINECELLHEIGHT        self.scaleHeight(54)
#define DEFINESEPHEIGHT         self.scaleHeight(21)
#define DEFINELEFTSPE           self.scaleiPhoneMargin(16)
#define CIECLESPE               self.scaleHeight(16)
#define DEFINESESSIONCELLHEIGHT self.scaleHeight(61)
#define DEFINELINEWIDTH         self.scaleHeight(0.1)
#define ForgetPwdView_CellH     50
#define SharePhotoCount         4  //每行顯示個數
#define SharePhotoSep           8  //中間空隙
#define SharePictureCount           10  //分享图片数
#define SharePhotoRightSep      self.scaleiPhoneMargin(26) //右邊空隙
#define SharePhotoWidthHeight   (kScreenW - DEFINELEFTSPE - SharePhotoRightSep - (SharePhotoCount - 1) * SharePhotoSep) / SharePhotoCount


#define ContentLeftSpace 40
#define ContentRightSpace 20

#define RGBA(r,g,b,a)       [UIColor colorWithRed:(r)/255.f \
green:(g)/255.f \
blue:(b)/255.f \
alpha:(a)]

#define RGB(r,g,b)          [UIColor colorWithRed:(r)/255.f \
green:(g)/255.f \
blue:(b)/255.f \
alpha:1.f]
#define Space 10

//朋友圈界面
#define VIEWWITHTAG(_OBJECT,_TAG)   (id)[_OBJECT viewWithTag : _TAG]
#define kGAP 10
#define kThemeColor [UIColor colorWithRed:0 green:(190 / 255.0) blue:(12 / 255.0) alpha:1]
#define kAvatar_Size 40

#define Localized(key) NSLocalizedString(key,nil)

#endif
