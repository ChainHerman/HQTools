//
//  ViewController.m
//  HQBeauty
//
//  Created by macq on 2019/3/19.
//  Copyright © 2019 HQ. All rights reserved.
//

#import "ViewController.h"
#import "ObtainViewController.h"
#import "GetAllPhotosViewController.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    UIButton * button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.backgroundColor = [UIColor purpleColor];
    [button addTarget:self action:@selector(pp) forControlEvents:UIControlEventTouchUpInside];
    button.frame = CGRectMake(20, 120, 90, 40);
    [button setTitle:@"join" forState:UIControlStateNormal];
    [self.view addSubview:button];
}

-(void)pp
{

    
    
    
   
    ObtainViewController  * vc = [ObtainViewController new];
//    GetAllPhotosViewController * vc = [GetAllPhotosViewController new];
    UINavigationController * na = [[UINavigationController alloc]initWithRootViewController:vc];
    [na setModalTransitionStyle:UIModalTransitionStylePartialCurl];
 
    
    
    [self presentViewController:na animated:YES completion:^{
        
    }];
}
@end
