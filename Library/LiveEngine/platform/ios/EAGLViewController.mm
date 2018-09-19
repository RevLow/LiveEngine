//
//  EAGLViewController.m
//  LiveEngine
//
//  Created by Tetsushi on 2018/01/08.
//  Copyright (c) 2018年 RevLow. All rights reserved.
//

#import "EAGLViewController.h"
#import "EAGLView.h"
#include "GLViewImpl-ios.h"

using namespace live;

@interface EAGLViewController ()

@end

@implementation EAGLViewController

- (id) init
{
    if (self = [super init])
    {
        EAGLView* view = [[EAGLView alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
        GLView* glView = new GLViewImpl((__bridge void*)view);
        
        Application::instance().initGLView(glView);

        self.view = view;
    }
    
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) viewWillLayoutSubviews {
    [super viewWillLayoutSubviews];
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation {
    [super didRotateFromInterfaceOrientation:fromInterfaceOrientation];
}

// ステータスバーを隠す
-(BOOL) prefersStatusBarHidden {
    return YES;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
