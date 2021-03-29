import java.awt.*;
import javax.swing.*;

public class ImageJPanel extends JPanel 
{
	ImageIcon image = null;
	boolean fillEntireArea = false;
	boolean tileImage = false;

	public ImageJPanel() 
	{
		super();
	}

	public void setFillEntireArea( boolean b ) 
	{
		fillEntireArea = b;
		repaint();
	}

	public boolean getFillEntireArea() 
	{
		return fillEntireArea;
	}

	public void setTileImage( boolean b ) 
	{
		tileImage = b;
		repaint();
	}

	public boolean getTileImage() 
	{
		return tileImage;
	}


	public void setImage( ImageIcon i ) 
	{
		image = i;
		repaint();
	}

	public ImageIcon getImage() 
	{
		return image;
	}

	public void paintComponent( Graphics g ) 
	{
		if (isOpaque()) 
		{
			super.paintComponent( g );
			if ( image != null ) 
			{
				int width = getWidth(), height = getHeight();

				g.setColor( getBackground() );
				g.fillRect( 0, 0, width, height );
				if ( fillEntireArea )
					g.drawImage( image.getImage(), 0, 0, width, height, this );
				else 
				{
					if ( !tileImage ) 
					{
						g.drawImage( image.getImage(),
							( width-image.getIconWidth() )/2,
							( height-image.getIconHeight() )/2,
							this );
					} 
					else 
					{
						int tileW = image.getIconWidth();
						int tileH = image.getIconHeight();
						int xpos, ypos, startx, starty;
						for ( ypos = 0; height - ypos > 0; ypos += tileH ) 
						{
							for ( xpos = 0; width - xpos > 0; xpos += tileW ) 
							{
								image.paintIcon( null, g, xpos, ypos );
							}
						}
					}
				}
			}
		}   
	}
}


