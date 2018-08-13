package l4;

import java.util.Date;

public class Item {
	private String title;
	private String description;
	private String Link;
	private Date pubDate;
	
	
	@Override
	public String toString() {
		return "Item [title=" + title + ", description=" + description +", PubDate: "+ pubDate + ", Link=" + Link + "]";
	}

	
	public Date getPubDate() {
		return pubDate;
	}

	public void setPubDate(Date pubDate) {
		this.pubDate = pubDate;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public String getLink() {
		return Link;
	}

	public void setLink(String link) {
		Link = link;
	}
}
