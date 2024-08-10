import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SecoundComponent } from './secound.component';

describe('SecoundComponent', () => {
  let component: SecoundComponent;
  let fixture: ComponentFixture<SecoundComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [SecoundComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(SecoundComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
