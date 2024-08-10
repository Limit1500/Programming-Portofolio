import { Routes } from '@angular/router';
import { FirstComponent } from './first/first.component';
import { SecoundComponent } from './secound/secound.component';
import { AppComponent } from './app.component';
import { ThirdComponent } from './third/third.component';

export const routes: Routes = [
    { path: 'first-component', component: FirstComponent},
    { path: 'secound-component', component: SecoundComponent},
    { path: 'third-component', component: ThirdComponent }
];
