package L4;

import java.util.Comparator;
import java.util.Date;

public class Item implements Comparator<Item>, Comparable<Item>{
    private String title;
    private String description;
    private String link;
    private Date pubDate;

    public Item() {
        title = null;
        description = null;
        link = null;
        pubDate = new Date(0);
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setLink(String link) {
        this.link = link;
    }

    public void setPubDate(Date pubDate) { this.pubDate = pubDate; }

    public String getTitle() {
        return title;
    }

    public String getDescription() {
        return description;
    }

    public String getLink() {
        return link;
    }

    public Date getPubDate() { return pubDate; }

    // supraincarcarea metodei toString()
    @Override
    public String toString()
    {
        String ret = title + "\n\t" + pubDate + "\n\t" + description + "\n\t" + link;
        return ret;
    }

    // supraincarcarea metode din interfata Comparatpr
    @Override
    public int compare(Item i1, Item i2) {
        return i1.getPubDate().compareTo(i2.getPubDate());
    }
    @Override
    public boolean equals(Object i) {
        return pubDate.equals(i);
    }
    @Override
    public int compareTo(Item i) {
        return pubDate.compareTo(i.getPubDate());
    }
}
