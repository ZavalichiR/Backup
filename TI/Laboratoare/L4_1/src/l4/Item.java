package l4;

public class Item {
	private String title;
	private String description;
	private String Link;
	
	@Override
	public String toString() {
		return "Item [title=" + title + ", description=" + description + ", Link=" + Link + "]";
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
