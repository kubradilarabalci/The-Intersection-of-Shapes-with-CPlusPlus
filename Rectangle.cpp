#include "Rectangle.h"
#include<iostream>
#include <GL/glut.h>
#include "Circle.h"
#include <cmath>
#include<string>
 void Rect::draw()
	{
		// Do NOT modify this function 
		if (m_bMarked)
			glColor4f(0.0f, 0.0f, 0.0f,0.5f);
		else
			glColor4f(m_col.r, m_col.g, m_col.b, 0.5f);
		glRectf(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y);
		
	}


 void Rect::drawBbox(Shape* pshape)
 {
	 
	 
	float leftBottomx, leftBottomy, rightUpperx, rightUppery;
	if(this->intersects(pshape))
	{
		// TODO: calculate leftBottomx, leftBottomy, rightUpperx, rightUppery points for surrounding bounding box
		Rect* prect=dynamic_cast<Rect*>(pshape);
		if(prect != NULL)
		{
			if(this->m_pos.x <= prect->m_pos.x){
				leftBottomx=this->m_pos.x;
				rightUpperx=prect->m_pos.x+prect->m_size.x;
				
				if(this->m_pos.y >= prect->m_pos.y){
					leftBottomy=prect->m_pos.y;
					rightUppery=this->m_pos.y+this->m_size.y;
					
				}
				
				else{
					leftBottomy=this->m_pos.y;
					rightUppery=prect->m_pos.y+prect->m_size.y;
				}
			}
			
			else{
				leftBottomx=prect->m_pos.x;
				rightUpperx=this->m_pos.x+this->m_size.x;
				
				if(prect->m_pos.y <= this->m_pos.y){
					rightUppery=this->m_pos.y+this->m_size.y;
					leftBottomy=prect->m_pos.y;
				}
				
				else{
					leftBottomy=this->m_pos.y;
					rightUppery=prect->m_pos.y+prect->m_size.y;
				}
			}
					
		}
	}	
	
	//Do NOT change this part
	glColor3f(1.0,0.0,0.0);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(leftBottomx,leftBottomy);
	glVertex2f(rightUpperx,leftBottomy);
	glVertex2f(rightUpperx,rightUppery);
	glVertex2f(leftBottomx,rightUppery);
	glEnd();
			
		
 }

 
 bool Rect::intersects(Shape* pshape)
	{
	
		Rect* prect=dynamic_cast<Rect*>(pshape);

	
		// TODO: write the implementation for this function
		//Rect* prect=dynamic_cast<Rect*>(pshape);

		if(prect)
		{
			if(this->m_pos.x < prect->m_pos.x){
				if(((this->m_pos.x+this->m_size.x)-prect->m_pos.x) >= 0 ){
					if(this->m_pos.y > prect->m_pos.y){
						if(((prect->m_pos.y+prect->m_size.y)-this->m_pos.y) >= 0)				
							return true;
					}
					else{
						if(((this->m_pos.y+this->m_size.y)-prect->m_pos.y) >= 0)				
							return true;
					}
				}
						
			}
			
			
			else{
				if(((prect->m_pos.x+prect->m_size.x)-this->m_pos.x) >= 0 ){
					if(prect->m_pos.y < this->m_pos.y)
					{
						if(((prect->m_pos.y+prect->m_size.y)-this->m_pos.y) >= 0)
							return true;		
					}
					
					else 
						if(((this->m_pos.y+this->m_size.y)-prect->m_pos.y) >= 0)				
							return true;	
				}

			}		
				
			
		}
		
		return false;
	}
